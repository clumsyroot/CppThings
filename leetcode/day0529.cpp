#include "list_struct.h"
#include "tree_struct.h"
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    // 判断是否是 2 的幂
    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & (n - 1)) == 0;
    }

    bool isPalindrome(ListNode *head)
    {
        std::vector<int> vals;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            vals.emplace_back(cur->val);
            cur = cur->next;
        }
        int low = 0, high = vals.size() - 1;
        while (low < high)
        {
            if (vals[low] != vals[high]) return false;
            low++;
            high--;
        }
        return true;
    }

    bool isAnagram(std::string s, std::string t)
    {
        if (s.length() != t.length()) return false;
        // std::unordered_map<char, int> count_s, count_t;
        // std::vector<char> count;
        // for (int i = 0; i < s.length(); i++)
        // {
        //     char _s = s.at(i), _t = t.at(i);
        //     if (count_s.find(_s) == count_s.end())
        //     {
        //         count_s[_s] = 1;
        //         count.emplace_back(_s);
        //     }
        //     else
        //     {
        //         count_s[_s]++;
        //     }
        //     if (count_t.find(_t) == count_t.end())
        //     {
        //         count_t[_t] = 1;
        //     }
        //     else
        //     {
        //         count_t[_t]++;
        //     }
        // }
        // for (auto &&i : count)
        // {
        //     if (count_s[i] != count_t[i]) return false;
        // }
        // return true;

        // 哈希表
        std::vector<int> alpha(26);
        for (int i = 0; i < s.length(); i++)
        {
            alpha[s.at(i) - 'a']++;
            alpha[t.at(i) - 'a']--;
        }
        for (auto &&i : alpha)
        {
            if (i != 0) return false;
        }
        return true;
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == nullptr) return NULL;
        std::stack<*TreeNode> stk;
        std::vector<std::string> ans;
        while (!stk.empty())
        {
            TreeNode *cur = stk.top();
            stk.pop();
            std::string cur_str = cur->val + "->";
            while (cur->left != nullptr)
            {
                stk.push(cur->left);
                cur_str = cur_str + "->" + cur->val;
            }
            ans.push_back(cur_str);
            while (cur->right != nullptr)
            {
                stk.push(cur->right);
                cur_str = cur_str + "->" + cur->val;
            }
        }
    }
};

int main()
{
    using namespace std;
    Solution solution;
    solution.isAnagram("rat", "car");

    return 0;
}