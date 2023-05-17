#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
// using std::cin;
// using std::cout;
// using std::endl;
// using std::queue;
// using std::stack;
// using std::vector;

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
        using namespace std;
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
        // vector<int> ans;
        // stack<TreeNode *> treeNode;
        // while (root != nullptr || !treeNode.empty())
        // {
        //     while (root != nullptr)
        //     {
        //         treeNode.push(root);
        //         root = root->left;
        //     }
        //     root = treeNode.top();
        //     treeNode.pop();
        //     ans.push_back(root->val);
        //     root = root->right;
        // }
        // return ans;

        // Morris 中序遍历 -- 空间复杂度仅为 O(1)
        vector<int> ans;
        TreeNode *predecessor = nullptr;
        while (root != nullptr)
        {
            if (root->left != nullptr)
            {
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root)
                {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr)
                {
                    predecessor->right = root;
                    root = root->left;
                }
                else
                {
                    ans.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            else
            {
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }

    void inorderTraversal(TreeNode *root, vector<int> &ans)
    {
        if (!root) return;
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }

    // 判断两棵树是否相同
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // 递归
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(q->right, p->right);
    }

    // 判断是否为 对称二叉树
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr) return true;

        // 递归
        // return isSymmetric(root->left, root->right);

        // 迭代
        queue<TreeNode *> cur;
        cur.push(root->left);
        cur.push(root->right);
        TreeNode *p, *q;
        while (!cur.empty())
        {
            p = cur.front();
            cur.pop();
            q = cur.front();
            cur.pop();
            if (!p && !q)
            {
                continue;
            }
            if ((!p || !q) || (p->val != q->val))
                return false;
            cur.push(p->left);
            cur.push(q->right);
            cur.push(p->right);
            cur.push(q->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode *p, TreeNode *q)
    {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }

    // 二叉树的最大深度
    int maxDepth(TreeNode *root)
    {
        if (!root) return 0;
        // 递归、深度优先搜索
        // return max(maxDepth(root->left), maxDepth(root->right)) + 1;

        // 广度优先搜索
        queue<TreeNode *> cur;
        cur.push(root);
        int ans = 0;
        while (!cur.empty())
        {
            int size = cur.size();
            while (!cur.empty())
            {
                TreeNode *node = cur.front();
                cur.pop();
                if (node->left)
                {
                    cur.push(node->left);
                }
                if (node->right)
                {
                    cur.push(node->right);
                }
                size--;
            }
            ans++;
        }
        return ans;
    }

    // 将有序数组转换成 二叉搜索树
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        // 递归
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode *sortedArrayToBST(vector<int> &nums, int left, int right)
    {
        if (left > right) return nullptr;

        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, left, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, right);
        return root;
    }

    // 给定一个二叉树, 判断它是否是高度平衡的二叉树
    bool isBalanced(TreeNode *root)
    {
        if (!root) return true;
        // 自顶向下的递归
        // 这样写会 ER！C++ 中非零值都为 true！
        // return !(abs(height(root->left) - height(root->right)) - 1) && isBalanced(root->left) && isBalanced(root->right);
        // 下面这样才对
        // return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        // 自底向上的递归
        return height(root) >= 0;
    }

    int height(TreeNode *root)
    {
        using namespace std;
        if (!root) return 0;

        int left_height = height(root->left);
        int right_height = height(root->right);
        if (left_height == -1 || right_height == -1 || abs(left_height - right_height) > 1)
        {
            return -1;
        }
        else
        {
            return max(left_height, right_height);
        }
    }

    // 二叉树的最小深度
    int minDepth(TreeNode *root)
    {
        if (root == nullptr) return 0;
        // 深度优先搜索 递归
        // if (!root->left && !root->right)
        // {
        //     return 1;
        // }
        // int min_depth = INT_MAX;
        // if (root->left)
        // {
        //     min_depth = min(minDepth(root->left), min_depth);
        // }
        // if (root->right)
        // {
        //     min_depth = min(minDepth(root->right), min_depth);
        // }
        // return min_depth + 1;

        // 广度优先搜索 直接返回搜索到的第一个叶子节点的深度
        queue<pair<TreeNode *, int>> node_que;
        node_que.emplace(root, 1);

        while (!node_que.empty())
        {
            TreeNode *cur = node_que.front().first;
            int depth = node_que.front().second;
            node_que.pop();
            if (cur->left == nullptr && cur->right == nullptr)
            {
                return depth;
            }
            if (cur->left != nullptr)
            {
                node_que.emplace(cur->left, depth + 1);
            }
            if (cur->right != nullptr)
            {
                node_que.emplace(cur->right, depth + 1);
            }
        }
        return 0;
    }

    // 路径总和 判断是否存在 到叶子节点的路径为 target
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr) return false;

        // 广度优先遍历 遇到路径和为 target 的叶子节点直接返回 true
        queue<pair<TreeNode *, int>> node_que;
        node_que.emplace(root, root->val);
        while (!node_que.empty())
        {
            TreeNode *cur = node_que.front().first;
            int distance = node_que.front().second;
            node_que.pop();
            if (cur->left == nullptr && cur->right == nullptr && distance == targetSum)
            {
                return true;
            }
            if (cur->left != nullptr)
            {
                node_que.emplace(cur->left, cur->left->val + distance);
            }
            if (cur->right != nullptr)
            {
                node_que.emplace(cur->right, cur->right->val + distance);
            }
        }
        return false;

        // 递归
        // if (root->left == nullptr && root->right == nullptr)
        // {
        //     return sum == root->val;
        // }
        // return hasPathSum(root->left, sum - root->left->val) || hasPathSum(root->right, sum - root->right->val);
    }

    // 二叉树的前序遍历 root->left->right
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr) return ans;
        // 迭代
        // stack<TreeNode *> node_stk;
        // node_stk.push(root);
        // while (!node_stk.empty())
        // {
        //     root = node_stk.top();
        //     node_stk.pop();
        //     ans.emplace_back(root->val);
        //     if (root->right != nullptr)
        //     {
        //         node_stk.emplace(root->right);
        //     }
        //     if (root->left != nullptr)
        //     {
        //         node_stk.emplace(root->left);
        //     }
        // }
        // return ans;

        // 递归
        preorder(root, ans);
        return ans;
    }

    void preorder(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr) return;
        ans.emplace_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    // 二叉树的后序遍历
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr) return ans;
        // 迭代
        stack<TreeNode *> node_stk;
        TreeNode *pre = nullptr;
        while (root != nullptr || !node_stk.empty())
        {
            while (root != nullptr)
            {
                node_stk.emplace(root);
                root = root->left;
            }
            root = node_stk.top();
            node_stk.pop();
            if (root->right == nullptr || root->right == pre)
            {
                ans.emplace_back(root->val);
                pre = root;
                root = nullptr;
            }
            else
            {
                node_stk.emplace(root);
                root = root->right;
            }
        }
        return ans;
    }

    // 翻转二叉树
    TreeNode *invertTree(TreeNode *root)
    {
        // 递归
        if (root == nullptr) return nullptr;
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

int main()
{
    Solution solution;
    // vector<int> nums;
    // nums.push_back(0);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(4);
    // nums.push_back(5);
    // solution.sortedArrayToBST(nums);
    // TreeNode *root = new TreeNode(3);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->right = new TreeNode(7);
    // root->right->left = new TreeNode(15);

    // bool ans = solution.isBalanced(root);
    cout << !(-1) << endl; // !(-1) --> false (-1) 为 true
    return 0;
}