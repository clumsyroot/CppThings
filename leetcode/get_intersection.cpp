#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // 相交链表 返回链表相交的节点的 val , 没有则返回 nullptr
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        using namespace std;
        // 遍历 时间复杂度 O(m+n) 空间复杂度 O(m)
        // ListNode *cur = headA;
        // vector<ListNode *> addr;

        // while (cur != nullptr)
        // {
        //     addr.emplace_back(cur);
        //     cur = cur->next;
        // }
        // cur = headB;
        // while (cur != nullptr)
        // {
        //     for (auto &&i : addr)
        //     {
        //         if (i == cur)
        //         {
        //             return cur;
        //         }
        //     }
        //     cur = cur->next;
        // }
        // return nullptr;

        // 双指针 时间复杂度 O(m+n) 空间复杂度 O(1)
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *p = headA, *q = headB;
        // while (p != nullptr || q != nullptr)
        // {
        //     if (p == q) return p;
        //     if (p == nullptr)
        //     {
        //         p = headB;
        //     }
        //     else
        //     {
        //         p = p->next;
        //     }
        //     if (q == nullptr)
        //     {
        //         q = headA;
        //     }
        //     else
        //     {
        //         q = q->next;
        //     }
        // }
        while (p != q)
        {
            p = p == nullptr ? headB : p->next;
            q = q == nullptr ? headA : q->next;
        }
        return p;
    }

    // Excel 列表名称 -- 进制转换 (26 进制)
    string convertToTitle(int columnNumber)
    {
        using namespace std;
        string ans;
        while (columnNumber != 0)
        {
            // ASCII 'A' = 65
            char cur = 65 + (columnNumber - 1) % 26;
            columnNumber = (columnNumber - cur + 65) / 26;
            ans.push_back(cur);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // 多数元素 返回数组中出现次数大于 [n/2] 的元素
    int majorityElement(vector<int> &nums)
    {
        using namespace std;
        int n = nums.size();
        
    }
};

int main()
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(1);
    head = head->next;
    head->next = new ListNode(8);

    Solution solution;
    solution.getIntersectionNode(head, head);

    return 0;
}