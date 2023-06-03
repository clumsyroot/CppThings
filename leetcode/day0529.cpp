#include "list_struct.h"
#include "tree_struct.h"
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
    // 此处 ans 传入的应该为引用
    void dfs(TreeNode *m_root, std::string m_path, std::vector<std::string> &ans)
    {
        if (m_root == nullptr) return;
        if (m_root->left == nullptr && m_root->right == nullptr)
        {
            ans.emplace_back(m_path + std::to_string(m_root->val));
        }
        m_path = m_path + std::to_string(m_root->val) + "->";
        dfs(m_root->left, m_path, ans);
        dfs(m_root->right, m_path, ans);
    }

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

    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        // 深度优先遍历 迭代
        // std::vector<std::string> ans;
        // if (root == nullptr) return ans;

        // std::stack<TreeNode *> node_stk;
        // std::stack<std::string> path_stk;
        // node_stk.push(root);
        // path_stk.push(std::to_string(root->val));

        // while (!node_stk.empty())
        // {

        //     TreeNode *cur = node_stk.top();
        //     std::string path = path_stk.top();
        //     node_stk.pop();
        //     path_stk.pop();
        //     if (cur->left == nullptr && cur->right == nullptr) ans.emplace_back(path);
        //     if (cur->right != nullptr)
        //     {
        //         node_stk.emplace(cur->right);
        //         path_stk.emplace(path + "->" + std::to_string(cur->right->val));
        //     }
        //     if (cur->left != nullptr)
        //     {
        //         node_stk.emplace(cur->left);
        //         path_stk.emplace(path + "->" + std::to_string(cur->left->val));
        //     }
        // }
        // return ans;

        // 深度优先遍历 递归
        std::vector<std::string> ans;
        dfs(root, "", ans);
        return ans;
    }

    int addDigits(int num)
    {
        while (num > 9)
        {
            int ans = 0;
            while (num > 0)
            {
                ans += num % 10;
                num = num / 10;
            }
            num = ans;
        }
        return num;
    }

    bool isUgly(int n)
    {
        if (n <= 0) return false;
        std::vector<int> factors = {2, 3, 5};
        for (auto &&i : factors)
        {
            while (n % i == 0)
            {
                n /= i;
            }
        }
        return n == 1;
    }

    int missingNumber(std::vector<int> &nums)
    {
        int n = nums.size();
        int total = n * (n + 1) / 2, sum = 0;
        for (auto &&i : nums)
        {
            sum += i;
        }
        return total - sum;
    }

    int firstBadVersion(int n)
    {
        // 二分查找
        int low = 0, high = n;
        while (low < high)
        {
            
        }
    }
};

int main()
{
    using namespace std;
    Solution solution;
    // solution.isAnagram("rat", "car");
    // TreeNode *root = new TreeNode(5);
    // TreeNode *cur = new TreeNode(3);
    // root = new TreeNode(2, nullptr, root);
    // root = new TreeNode(1, root, cur);

    // solution.binaryTreePaths(root);
    // solution.addDigits(38);
    std::vector<int> test = {1, 2, 3, 4};
    solution.missingNumber(test);

    return 0;
}