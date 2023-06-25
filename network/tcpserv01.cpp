#include "socket/mysocket.h"

void str_serv(int m_sock_fd)
{
    ssize_t n;
    char buf[4096];

    while (true)
    {
        while ((n = read(m_sock_fd, buf, 4096)) > 0)
        {
            write(m_sock_fd, buf, n);
        }
        if (n < 0 && errno == 4)
        {
            exit(0);
        }
        else if (n < 0)
        {
            perror("str_serv: read error");
        }
    }
}

int main(int argc, char const *argv[])
{
    int sock_fd, conn_fd;
    pid_t child_pid;
    socklen_t client_addrlen;
    struct sockaddr_in client_addr, server_addr;

    sock_fd = Socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(9877);

    Bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    Listen(sock_fd, 5);

    while (true)
    {
        client_addrlen = sizeof(client_addr);
        conn_fd = Accept(sock_fd, (struct sockaddr *)&client_addr, &client_addrlen);
        if ((child_pid = Fork()) == 0) // fork() 返回 0 --> 子进程
        {
            Close(sock_fd);
            str_serv(conn_fd);
            exit(0);
        }
        Close(conn_fd);
    }
    return 0;
}
