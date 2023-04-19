#include <iostream>

int main()
{
    using namespace std;
    int updates = 6;
    int *p_updates; // * 运算符, 将其应用于指针, 可以得到该地址处存储的值
    double *d_updates;
    p_updates = &updates;

    cout << "Value: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;
    cout << "Address: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;

    cout << "Size of Int * is " << sizeof(p_updates) << " Bytes." << endl;
    cout << "Size of Double * is " << sizeof(d_updates) << " Bytes." << endl;

    int higgens = 5;
    int *pt = &higgens; // VALID 'int*' 和 'int' 是两种类型
    // *pt = &higgens;     // INVALID invalid conversion from ‘int*’ to ‘int’ [-fpermissive]
    // pt -- 指针类型  *pt 整数型
    cout << "Value of higgens = " << higgens
         << ", address of higgens = " << &higgens << endl;
    cout << "Value of *pt = " << *pt
         << ", value of pt = " << pt << endl;

    int *addr;
    addr = (int *)0xB8000000;

    return 0;
}