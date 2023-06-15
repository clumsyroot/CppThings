#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, n;
    char recvline[4096];
    struct sockaddr_in servaddr;

    if (argc != 3)
    {
        printf("WARNING! usage: <program> <IpAddress> <Port>\n");
        return 1;
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket error");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) printf("inet_pton error for %s", argv[1]);
    if (connect(sockfd, (sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connnet error");
        return 1;
    };

    while ((n = read(sockfd, recvline, 4096)) > 0)
    {
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF) perror("fputs error");
    }
    if (n < 0)
    {
        perror("read error");
        return 1;
    }

    return 0;
}