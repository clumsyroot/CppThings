#include <climits>
#include <iostream>

int main()
{
    // 计算机中数值用 补码 存储
    using namespace std;
    int max_int = INT_MAX; // 2^bits - 1
    int min_int = INT_MIN; // - 2^bits
    unsigned int u_int = UINT_MAX;
    cout << "Win64 int is " << sizeof(int) << " bytes." << endl;    // win64 -- 4 bytes
    cout << "Win64 int long " << sizeof(long) << " bytes." << endl; // win64 -- 8 bytes
    cout << max_int << endl;
    cout << min_int << endl;
    cout << u_int << endl;

    return 0;
}