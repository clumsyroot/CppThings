#include <climits>
#include <iostream>

int main()
{
    // 计算机中数值用 补码 存储
    using namespace std;
    int max_int = INT_MAX; // 2^bits - 1
    int min_int = INT_MIN; // - 2^bits
    int t;
    t = min_int - 1; // 下溢
    unsigned int u_int = UINT_MAX;
    cout << "Win64 int is " << sizeof(int) << " bytes." << endl;    // win64 -- 4 bytes
    cout << "Win64 int long " << sizeof(long) << " bytes." << endl; // win64 -- 8 bytes
    cout << "Win64 Int Max is " << max_int << endl;
    cout << "Win64 Int Min is " << min_int << endl;
    cout << "Win64 Unsigned Int Max is " << u_int << endl;
    cout << "负数下溢变成最大正数" << t << endl;

    // 进制
    int chest = 42;
    cout << "decimal " << chest << endl;
    cout << hex << "hex " << chest << endl;
    cout << oct << "octal " << chest << endl;

    char ch = 65; // char 整型 存储字符对应的数值编码
    cout << '$' << endl;
    cout.put('$') << endl;
    cout << ch << endl;
    char alarm = '\a';
    int n_alarm = alarm;
    cout << alarm << "Don't do that again!\a\n";
    cout << n_alarm << endl;

    return 0;
}