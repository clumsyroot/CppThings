#include <bitset>
#include <iostream>

class Solution
{
private:
    // uint32_t --> unsigned int
    // uint16_t --> unsigned short int
    // uint8_t --> unsigned char
    const uint32_t M1 = 0x55555555;
    const uint32_t M2 = 0x33333333;
    const uint32_t M4 = 0x0f0f0f0f;
    const uint32_t M8 = 0x00ff00ff;

public:
    // 颠倒给定的 32 位无符号二进制位
    uint32_t reverseBits(uint32_t n)
    {
        using namespace std;
        // n = n >> 1 & M1 | (n & M1) << 1;
        // n = n >> 2 & M2 | (n & M2) << 2;
        // n = n >> 4 & M4 | (n & M4) << 4;
        // n = n >> 8 & M8 | (n & M8) << 8;

        // return n >> 16 | n << 16;

        cout << bitset<32>(n) << endl;
        n = (n >> 16) | (n << 16);
        n = ((n >> 8) & 0x00ff00ff) | ((n << 8) & 0xff00ff00);
        n = ((n >> 4) & 0x0f0f0f0f) | ((n << 4) & 0xf0f0f0f0);
        n = ((n >> 2) & 0x33333333) | ((n << 2) & 0xcccccccc);
        n = ((n >> 1) & 0x55555555) | ((n << 1) & 0xaaaaaaaa);
        cout << bitset<32>(n) << endl;

        return n;
    }
};

int main()
{
    using namespace std;
    Solution solution;

    uint32_t a = 43261596;
    solution.reverseBits(a);

    return 0;
}