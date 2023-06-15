#include <arpa/inet.h>
#include <cstdio>

int main()
{
    struct in_addr addr;
    addr.s_addr = inet_addr("192.168.0.1");
    printf("网络字节序表示的地址: %d\n", addr.s_addr);

    char *ip_str = inet_ntoa(addr);
    if (ip_str != NULL)
    {
        printf("IPv4 address: %s\n", ip_str);
    }
    else
    {
        printf("Failed to convert address.\n");
    }

    struct in_addr ipv4_addr;
    const char *ipv4_str = "192.168.0.1";
    // INET_ADDRSTRLEN -- ipv4 地址字符串的长度 "192.168.1.1\0"
    char ipv4_buf[INET_ADDRSTRLEN];
    // int inet_pton (int __af, const char *__restrict __cp, void *__restrict __buf)
    // 将十进制地址转换成网络字节序地址
    if (inet_pton(AF_INET, ipv4_str, &(ipv4_addr.s_addr)) > 0)
    {
        printf("网络字节序地址为: %d\n", ipv4_addr.s_addr);
        // char *inet_ntop (int __af, const void *__restrict __cp, char *__restrict __buf, socklen_t __len)
        // 将网络字节序地址转换成十进制地址
        if (inet_ntop(AF_INET, &(ipv4_addr.s_addr), ipv4_buf, INET_ADDRSTRLEN) > 0)
        {
            printf("IPV4 地址为: %s\n", ipv4_buf);
        }
        else
        {
            perror("inet_ntop");
            return 1;
        }
    }
    else
    {
        perror("inet_pton");
        return 1;
    }

    return 0;
}
