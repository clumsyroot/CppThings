#include "mysocket.h"
#include <iostream>

// socket wrap
int Socket(int m_family, int m_type, int m_protocol)
{
    int n;
    if ((n = socket(m_family, m_type, m_protocol)) < 0)
    {
        std::cerr << "socket error";
        // perror("scoket error");
        abort();
    }
    return n;
}

// socket bind wrap
void Bind(int m_socketfd, struct sockaddr *m_address, socklen_t m_salenptr)
{
    if (bind(m_socketfd, m_address, m_salenptr) < 0)
    {
        perror("socket bind error");
        abort();
    }
}

// socket listen wrap
void Listen(int m_socketfd, int m_blacklog)
{
    if (listen(m_socketfd, m_blacklog) < 0)
    {
        perror("socket listen error");
        abort();
    }
}

// socket connect wrap
void Connect(int m_sockfd, sockaddr *m_address, socklen_t m_salen)
{
    if (connect(m_sockfd, m_address, m_salen) < 0)
    {
        perror("socket connect error");
        abort();
    }
}

// socket accept wrap
int Accept(int m_socketfd, struct sockaddr *m_sa, socklen_t *m_salenptr)
{
    int n;
    if ((n = accept(m_socketfd, m_sa, m_salenptr)) < 0)
    {
        perror("socket accept error");
        abort();
    }
    return n;
}

void Close(int m_sockfd)
{
    if (close(m_sockfd) < 0)
    {
        perror("socket close error");
        abort();
    }
}

pid_t Fork()
{
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        perror("fork error");
        abort();
    }
    return pid;
}