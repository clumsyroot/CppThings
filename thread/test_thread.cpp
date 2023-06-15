#include <iostream>
#include <unistd.h>

int main()
{
    std::cout << "主进程 pid " << getpid() << std::endl;
    int pid = fork();
    std::cout << pid << std::endl;

    return 0;
}