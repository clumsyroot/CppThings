#include "mysocket.h"

void str_cli(FILE *fp, int m_sock_fd)
{
    char send_line[4096], recv_line[4096];
    while (fgets(send_line, 4096, fp) != NULL)
    {
        write(m_sock_fd, send_line, strlen(send_line));
        if (read(m_sock_fd, recv_line, 4096) == 0)
        {
            perror("strcli: server error");
        }
        fputs(recv_line, stdout);
    }
}

int main(int argc, char const *argv[])
{
    int sock_fd;
    struct sockaddr_in server_addr;

    if (argc != 2)
    {
        printf("usage: <program> <IPaddress>");
        exit(0);
    }

    sock_fd = Socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9877);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    Connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    str_cli(stdin, sock_fd);

    return 0;
}
