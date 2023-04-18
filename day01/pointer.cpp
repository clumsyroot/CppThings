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

    return 0;
}