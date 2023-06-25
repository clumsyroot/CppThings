#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int Socket(int __family, int __type, int __protocol);
void Bind(int __socket_fd, struct sockaddr *__address, socklen_t __socket_addr_len);
void Listen(int __socket_fd, int __blacklog);
void Connect(int __socket_fd, sockaddr *__address, socklen_t __socket_addr_len);
int Accept(int __socket_fd, struct sockaddr *__address, socklen_t *__socket_addr_len);
void Close(int __socket_fd);
pid_t Fork();
