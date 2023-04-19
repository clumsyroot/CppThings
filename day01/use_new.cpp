#include <iostream>

int main()
{
    using namespace std;
    // int *pn = new int; // allocate space for an int
    // cout << pn << endl;
    // cout << *pn << endl;

    int nights = 1001;
    int *pt = new int;
    *pt = 1001;
    cout << "nights value = " << nights
         << ", localtion = " << &nights << endl;
    cout << "int value = " << *pt
         << ", localtion = " << pt << endl;

    double *pd = new double;
    *pd = 10000001.0;
    cout << "double value = " << *pd
         << ", localtion = " << pd << endl;
    cout << "size of pt = " << sizeof(pt)
         << ", size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof(pd)
         << ", size of *pd = " << sizeof(*pd) << endl;

    return 0;
}