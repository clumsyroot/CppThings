#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <sys/socket.h>

int Socket(int m_family, int m_type, int m_protocol)
{
    int n;

    if ((n = socket(m_family, m_type, m_protocol)) < 0)
    {
        perror("scoket error");
        abort();
    }
    return n;
}

void Bind(int m_socketfd, struct sockaddr *m_address, socklen_t m_salenptr)
{
    if (bind(m_socketfd, m_address, m_salenptr) < 0)
    {
        perror("socket bind error");
        abort();
    }
}

void Listen(int m_socketfd, int m_blacklog)
{
    if (listen(m_socketfd, m_blacklog) < 0)
    {
        perror("socket listen error");
        abort();
    }
}

void Connect(int m_sockfd, sockaddr *m_address, socklen_t m_salen)
{
    if (connect(m_sockfd, m_address, m_salen) < 0)
    {
        perror("socket connect error");
        abort();
    }
}

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