#include "list_struct.h"
#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
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

    // 移除链表中的元素
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

        // 递归
        // if (head == nullptr) return nullptr;

        // head->next = removeElements(head->next, val);
        // if (head->val == val)
        // {
        //     return head->next;
        // }
        // else
        // {
        //     return head;
        // }
    }

    bool isIsomorphic(string s, string t)
    {
        using namespace std;
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;

        for (int i = 0; i < s.length(); i++)
        {
            char s_i = s.at(i), t_i = t.at(i);
            if ((s2t.count(s_i) && s2t[s_i] != t_i) || (t2s.count(t_i) && t2s[t_i] != s_i))
            {
                return false;
            }
            s2t[s_i] = t_i;
            t2s[t_i] = s_i;
        }
        return true;
    }

    // 反转链表
    ListNode *reverseList(ListNode *head)
    {
        using namespace std;
        if (head == nullptr) return nullptr;

        // 逻辑推理
        // ListNode *cur = head;
        // vector<int> index;
        // int count = 0;
        // while (cur != nullptr)
        // {
        //     index.emplace_back(cur->val);
        //     cur = cur->next;
        //     count++;
        // }
        // cur = head;
        // while (count > 0)
        // {
        //     cur->val = index[count - 1];
        //     count--;
        //     cur = cur->next;
        // }
        // return head;

        // 双指针
        ListNode *pre = head, *cur = nullptr, *t;
        while (pre != nullptr)
        {
            t = pre->next;
            pre->next = cur;
            cur = pre;
            pre = t;
        }
        return cur;
    }

    // 判断数组中是否存在重复元素
    bool containsDuplicate(vector<int> &nums)
    {
        using namespace std;
        unordered_map<int, int> umap;
        for (auto &&i : nums)
        {
            if (umap.find(i) == umap.end())
            {
                umap[i] = 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    // 是否存在重复元素 II
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        using namespace std;
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++)
        {
            if (umap.find(nums[i]) == umap.end())
            {
                umap[nums[i]] = i;
            }
            else
            {
                if (i - umap[nums[i]] <= k) return true;
                umap[nums[i]] = i;
            }
        }
        return false;
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