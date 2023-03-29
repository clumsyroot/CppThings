#include <iostream>

using namespace std;

int main()
{
    int &&a = 1; // 分配一块新的内存空间、此块内存空间叫 a
    int b = a;   // 会分配一块新的内存空间、此块内存空间叫 b
    // int &b = a;  // 与上一句的区别在于 -- 此处不会新分配内存空间、依然指向 &a
    int *p = &b; // p -- 指针 存储着一个地址, 即 &b

    cout << &a << endl;
    cout << &b << endl;
    cout << p << endl;
    return 0;
}