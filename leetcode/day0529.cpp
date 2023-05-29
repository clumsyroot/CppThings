#include <iostream>
#include <stack>
#include <vector>

class Solution
{
public:
    // 判断是否是 2 的幂
    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

