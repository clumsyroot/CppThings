#include "list_struct.h"
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

    // 统计 二进制 中 1 的个数
    int hammingWeight(uint32_t n)
    {
        using namespace std;
        cout << bitset<32>(n) << endl;

        int ans = 0;
        // 顺序查找
        // for (int i = 0; i < 32; i++)
        // {
        //     if (n & (1 << i))
        //     {
        //         ans++;
        //     }
        // }

        // 优化 -- n & (n - 1) 为将 n 位二进制中最低位的 1 变为 0 后的结果
        while (n)
        {
            n &= (n - 1);
            ans++;
        }
        return ans;
    }

    // 快慢指针
    bool isHappy(int n)
    {
        int slowRunner = n;
        int fastRunner = getNext(n);
        while (fastRunner != 1 || fastRunner != slowRunner)
        {
            slowRunner = getNext(slowRunner);
            fastRunner = getNext(getNext(fastRunner));
        }
        return fastRunner == 1;
    }

    ListNode *removeElements(ListNode *head, int val)
    {
        // 先对头节点做处理
        // if (head == nullptr) return head;
        // while (head->val == val)
        // {
        //     head = head->next;
        //     if (head == nullptr) return head;
        // }

        // ListNode *cur = head;
        // while (cur->next != nullptr)
        // {
        //     if (cur->next->val == val)
        //     {
        //         cur->next = cur->next->next;
        //     }
        //     else
        //     {
        //         cur = cur->next;
        //     }
        // }

        // return head;

        // 在头节点之前添加虚拟节点 dummyNode, 最后返回 dummyNode -> next
        ListNode *dummyNode = new ListNode(val - 1);
        dummyNode->next = head;

        ListNode *cur = dummyNode;
        while (cur->next != nullptr)
        {
            if (cur->next->val == val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummyNode->next;
    }

private:
    int getNext(int n)
    {
        int totalSum = 0;
        while (n > 0)
        {
            int cur = n % 10;
            totalSum += cur * cur;
            n = n / 10;
        }
        return totalSum;
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