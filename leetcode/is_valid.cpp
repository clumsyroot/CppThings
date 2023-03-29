#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
// #include <string>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // 有效的括号
    bool isValid(string s)
    {
        int length = s.size();
        if (length % 2 == 1)
        {
            return false;
        }
        unordered_map<char, char> symbool_pairs = {
            {']', '['},
            {')', '('},
            {'}', '{'},
        };

        stack<char> str_stack;
        for (char ch : s)
        {
            // count(key) 查找以 key 为键的键值对的个数
            if (symbool_pairs.count(ch))
            {
                if (str_stack.empty() || str_stack.top() != symbool_pairs[ch])
                {
                    return false;
                }
                str_stack.pop();
            }
            else
            {
                str_stack.push(ch);
            }
        }
        return str_stack.empty();
    }

    // 合并两个有序链表
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 迭代
        // ListNode *preHead = new ListNode(-1);
        // ListNode *tail = preHead;
        // while (list1 && list2)
        // {
        //     if (list1->val <= list2->val)
        //     {
        //         tail->next = list1;
        //         list1 = list1->next;
        //     }
        //     else
        //     {
        //         tail->next = list2;
        //         list2 = list2->next;
        //     }
        //     tail = tail->next;
        // }
        // tail->next = list1 ? list1 : list2;
        // return preHead->next;

        // 递归
        if (!list1)
        {
            return list2;
        }
        else if (!list2)
        {
            return list1;
        }
        else if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
        }
    }

    // 删除有序数组中的重复项
    int removeDuplicates(vector<int> &nums)
    {
        // 顺序遍历迁移
        // int idx = -1;
        // int key;
        // for (auto &&num : nums)
        // {
        //     if (num != key)
        //     {
        //         idx++;
        //         key = num;
        //         num[idx] = key;
        //     }
        // }
        // return idx + 1;

        // 双指针
        // int p = 0, q = 1;
        // while (q < nums.size())
        // {
        //     if (nums[p] != nums[q])
        //     {
        //         if (q - p > 1)
        //         {
        //             nums[p + 1] = nums[q];
        //             ++p;
        //         }
        //     }
        //     ++q;
        // }
        // return p + 1;

        // 优化
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[j] != nums[i])
            {
                nums[++j] = nums[i];
            }
        }
        return j + 1;
    }

    // 删除数组中的指定项 要求空间复杂度 O(1)
    int removeElement(vector<int> &nums, int val)
    {
        int idx = 0;
        for (auto &&num : nums)
        {
            if (num != val)
            {
                nums[idx++] = num;
            }
        }
        return idx;
    }

    // 搜索插入位置
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1, mid;
        if (high < 0)
        {
            return 0;
        }

        // while (low <= high)
        // {
        //     mid = (low + high) / 2;
        //     if (nums[mid] > target)
        //     {
        //         high = mid - 1;
        //     }
        //     else if (nums[mid] < target)
        //     {
        //         low = mid + 1;
        //     }
        //     else
        //     {
        //         return mid;
        //     }
        // }
        // return nums[mid] < target ? mid + 1 : mid;

        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }

    // 返回最后一个单词的长度
    int lengthOfLastWord(string s)
    {
        // 正向遍历
        // int res = 0;
        // bool flag = false;
        // for (int i = 0; i < s.length(); i++)
        // {
        //     if (s[i] != ' ')
        //     {
        //         if (flag == false)
        //         {
        //             res = 0;
        //             flag = true;
        //         }
        //         res++;
        //         continue;
        //     }
        //     flag = false;
        // }
        // return res;

        // 反向寻找第一个字符串
        // int res = 0;
        // for (int i = s.length() - 1; i >= 0; i--)
        // {
        //     if (s[i] == ' ' && !res)
        //     {
        //         continue;
        //     }
        //     else if (s[i] == ' ' && res)
        //     {
        //         return res;
        //     }
        //     res++;
        // }
        // return res;

        int idx = s.length() - 1;
        while (s[idx] == ' ')
        {
            idx--;
        }
        int res = 0;
        while (idx >= 0 && s[idx] != ' ')
        {
            res++;
            idx--;
        }
        return res;
    }

    // 给定由数组组成的整数，返回加一后的数组
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        int cur = 1;
        int key;

        // for (int i = n - 1; i >= 0; i--)
        // {
        //     key = digits[i] + cur;
        //     digits[i] = key % 10;
        //     cur = key >= 10 ? 1 : 0;
        // }
        // if (cur > 0)
        // {
        //     digits.emplace(digits.begin(), 1);
        // }
        // return digits;

        // 优化
        while (cur && n)
        {
            key = digits[n - 1] + cur;
            digits[n - 1] = key % 10;
            if (key < 10)
            {
                return digits;
            }
            n--;
        }
        digits.emplace(digits.begin(), 1);
        return digits;
    }

    // 二进制求和
    string addBinary(string a, string b)
    {
        // int m = a.length(), n = b.length(), cur = 0;
        // int key;
        // char t;
        // string ans;
        // int max = m > n ? m : n;
        // for (int i = max - 1; i >= 0; i--)
        // {
        //     key = a[i] + b[i] + cur;
        //     t = (char)(key - 2);
        //     // t = key % 2;
        //     ans.append(&t);
        //     if (key < 2)
        //     {
        //         cur = 0;
        //     }
        //     else
        //     {
        //         cur = 1;
        //     }
        // }
        // return ans;

        string ans;
        int m = a.length() - 1, n = b.length() - 1;
        int carry = 0;
        while (m >= 0 || n >= 0)
        {
            int key = carry;
            // 注意 字符 如何参与运算
            key += m >= 0 ? a.at(m) - '0' : 0;
            key += n >= 0 ? b.at(n) - '0' : 0;
            if (key % 2)
            {
                ans.append("1");
            }
            else
            {
                ans.append("0");
            }
            carry = key / 2;
            m--;
            n--;
        }
        if (carry)
        {
            ans.append("1");
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // x 的平方根
    int mySqrt(int x)
    {
        int low = 1, high = x / 2, mid, ans = -1;
        if (x == 0 || x == 1)
        {
            return x;
        }
        while (low <= high)
        {
            mid = (low + high) / 2;
            if ((long long)mid * mid <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }

    // 爬楼梯的方法数
    int climbStairs(int n)
    {
        // 递归 --- 会超时
        // if (n == 1)
        // {
        //     return 1;
        // }
        // if (n == 2)
        // {
        //     return 2;
        // }
        // return climbStairs(n - 1) + climbStairs(n - 2);

        // 动态规划 f(x) = f(x-1) + f(x-2)
        int p = 0, q = 0, ans = 1;
        for (int i = 1; i <= n; i++)
        {
            p = q;
            q = ans;
            ans = p + q;
        }
        return ans;

        // 直接求通项公式 特征方程 x^2 = x + 1
        // double sqrt5 = sqrt(5);
        // double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        // return (int)round(fibn / sqrt5);
    }
};

int main()
{
    Solution solution;
    // bool res = solution.isValid("{}({{{}}})");
    // cout << res << endl;
    // ListNode *l1;
    // ListNode *l2;

    // ListNode *res = solution.mergeTwoLists(l1, l2);
    // vector<int> nums;
    // nums.push_back(1);
    // nums.push_back(3);
    // nums.push_back(5);
    // nums.push_back(6);
    // int res = solution.searchInsert(nums, 2);
    string res = solution.addBinary("1010", "1011");
    cout << res << endl;

    return 0;
}