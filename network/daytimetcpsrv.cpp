#include "mysocket.h"
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <strings.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buff[4096];
    socklen_t len;
    time_t ticks;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(1234); // daytime server

    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    Listen(listenfd, 5);

    for (;;)
    {
        len = sizeof(cliaddr);
        connfd = Accept(listenfd, (sockaddr *)&cliaddr, &len);
        printf("connection from %s, port %d\n",
               inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)),
               //    ntohs(cliaddr.sin_port));
               cliaddr.sin_port);

        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        write(connfd, buff, strlen(buff));

        close(connfd);
    }
}
