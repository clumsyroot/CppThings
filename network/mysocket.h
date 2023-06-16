#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int Socket(int, int, int);
void Bind(int, struct sockaddr *, socklen_t);
void Listen(int, int);
void Connect(int, sockaddr *, socklen_t);
int Accept(int, struct sockaddr *, socklen_t *);