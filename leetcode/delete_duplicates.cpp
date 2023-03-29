#include <iostream>

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

        //优化
        
    }
};

int main()
{
    Solution solution;

    return 0;
}