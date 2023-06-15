#include "mynetwork.h"
// #include <sys/socket.h>
#include <cstdio>
#include <cstring>
#include <time.h>

int main(int argc, char const *argv[])
{
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket error");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(1234);

    bind(listenfd, (sockaddr_in *)&servaddr, sizeof(servaddr));
    listen(listenfd, 1024);

    for (;;)
    {
        connfd = accept(listenfd, (sockaddr *)NULL, NULL);

        ticks = time(NULL);

        snprintf(buf, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        send(connfd, buff, strlen(buff));
        
    }

    return 0;
}