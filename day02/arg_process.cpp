#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // 'argc' 包含了命令行参数的个数 (包括程序名称本身)
    // 'argv' 参数是指向每一个命令行参数的指针数组
    using namespace std;
    int opt;
    const char *str = "p:l:m:o:s:t:c:a:";
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }

    while ((opt = getopt(argc, argv, str)) != -1)
    {
        switch (opt)
        {
        case 'p':
            printf("opt is p, optarg is: %s\n", optarg);
            break;
        case 'l':
            printf("opt is l, optarg is: %s\n", optarg);
            break;
        case 'm':
            printf("opt is m, optarg is: %s\n", optarg);
            break;
        case 'o':
            printf("opt is o, optarg is: %s\n", optarg);
            break;
        case 's':
            printf("opt is s, optarg is: %s\n", optarg);
            break;
        case 't':
            printf("opt is t, optarg is: %s\n", optarg);
            break;
        case 'c':
            printf("opt is c, optarg is: %s\n", optarg);
            break;
        case 'a':
            printf("opt is a, optarg is: %s\n", optarg);
            break;
        default:
            cout << "Invalid option: " << opt << endl;
            break;
        }
    }

    return 0;
}