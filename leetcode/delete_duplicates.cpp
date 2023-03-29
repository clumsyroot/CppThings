#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // 删除顺序链表中的重复元素
    ListNode *deleteDuplicates(ListNode *head)
    {
        // ListNode *tail = head, *cur = head;
        // while (tail)
        // {
        //     if (tail->val != cur->val)
        //     {
        //         cur->next = tail;
        //         cur = tail;
        //     }
        //     tail = tail->next;
        //     cur->next = nullptr;
        // }
        // return head;

        // 优化
        ListNode *cur = head;
        while (cur != nullptr && cur->next != nullptr)
        {
            if (cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }

    // 合并两个有序数组
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // int idx = nums1.size() - 1;
        // while (m > 0 && n > 0)
        // {
        //     if (nums1[m - 1] >= nums2[n - 1])
        //     {
        //         nums1[idx] = nums1[m - 1];
        //         m--;
        //     }
        //     else
        //     {
        //         nums1[idx] = nums2[n - 1];
        //         n--;
        //     }
        //     idx--;
        // }
        // if (n > 0)
        // {
        //     for (int i = n - 1; i >= 0; i--)
        //     {
        //         nums1[idx] = nums2[i];
        //         idx--;
        //     }
        // }

        // 优化
        int idx = nums1.size() - 1;
        m--;
        n--;
        while (n >= 0)
        {
            while (m >= 0 && nums1[m] > nums2[n])
            {
                swap(nums1[idx--], nums1[m--]);
            }
            swap(nums1[idx--], nums2[n--]);
        }
    }

    // 二叉树中序遍历
    vector<int> inorderTraversal(TreeNode *root)
    {
        // 递归
        // vector<int> ans;
        // inorderTraversal(root, ans);
        // return ans;

        // 迭代
        vector<int> ans;
        stack<TreeNode *> treeNode;
        while (root != nullptr || !treeNode.empty())
        {
            while (root != nullptr)
            {
                treeNode.push(root);
                root = root->left;
            }
            root = treeNode.top();
            treeNode.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }

    void inorderTraversal(TreeNode *root, vector<int> &ans)
    {
        if (!root)
        {
            return;
        }
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }
};

int main()
{
    Solution solution;
    return 0;
}