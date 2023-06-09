#include "list_struct.h"
#include "tree_struct.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    int findRepeatNumber(std::vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == i)
            {
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i]) return nums[i];
            std::swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }

    bool findNumberIn2DArray(std::vector<std::vector<int>> &matrix, int target)
    {
        // 以左下角为搜索起点
        int i = matrix.size() - 1, j = 0;

        while (i >= 0 && j < matrix[0].size())
        {
            int &cur = matrix[i][j];
            if (cur == target) return true;
            if (cur > target)
            {
                i--;
            }
            else
            {
                j++;
            }
        }
        return false;
    }

    std::string replaceSpace(std::string s)
    {
        // std::string ans;
        // for (int i = 0; i < s.length(); i++)
        // {
        //     if (s.at(i) == ' ')
        //     {
        //         ans += "%20";
        //         continue;
        //     }
        //     ans += s.at(i);
        // }
        // return ans;

        int count = 0, len = s.size();
        // 统计空格数量
        for (auto &&c : s)
        {
            if (c == ' ') count++;
        }
        // resize s 长度
        s.resize(len + 2 * count);
        // 倒序遍历修改
        for (int i = len - 1, j = s.size() - 1; i < j; i--, j--)
        {
            if (s[i] != ' ')
                s[j] = s[i];
            else
            {
                s[j--] = '0';
                s[j--] = '2';
                s[j] = '%';
            }
        }
        return s;
    }

    std::vector<int> reversePrint(ListNode *head)
    {
        // ListNode *cur = head;
        // std::vector<int> index;
        // while (cur != nullptr)
        // {
        //     index.emplace_back(cur->val);
        //     cur = cur->next;
        // }
        // std::vector<int> ans;
        // for (int i = index.size() - 1; i > -1; i--)
        // {
        //     ans.emplace_back(index[i]);
        // }
        // return ans;

        // 递归
        std::vector<int> ans;
        m_reversePrint(head, ans);
        return ans;
    }

    void m_reversePrint(ListNode *node, std::vector<int> &index)
    {
        // 注意使用引用 &
        if (node != nullptr)
        {
            m_reversePrint(node->next, index);
            index.emplace_back(node->val);
        }
    }

    // TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    // {
    // }

    int fib(int n)
    {
        std::unordered_map<int, int> map;
        return m_fib(n, map);
    }

    int m_fib(int n, std::unordered_map<int, int> &map)
    {
        if (n == 0 || n == 1) return n;
        if (map.find(n) != map.end())
        {
            return map[n];
        }
        int cur = (m_fib(n - 1, map) + m_fib(n - 2, map)) % 1000000007;
        map[n] = cur;
        return cur;
    }
};

int main()
{
    using namespace std;
    Solution solution;
    // ListNode *cur = new ListNode(2);
    // cur = new ListNode(3, cur);
    // ListNode *root = new ListNode(1, cur);
    // std::cout << root << std::endl;
    // solution.reversePrint(root);
    int ans = solution.fib(20);
    cout << ans << endl;

    return 0;
}