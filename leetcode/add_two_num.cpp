#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    // 构造函数
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2)
        {
            // 判断链表是否为空、不为空则 n = val
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head)
            {
                // head 为空时
                head = tail = new ListNode(sum % 10);
            }
            else
            {
                // head 不为空时
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        // 最后一位是否进一
        if (carry > 0)
        {
            tail->next = new ListNode(carry);
        }
        return head;
    }

    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        if (x / 10 == 0)
        {
            return true;
        }
        // vector<int> num;
        // while ((x / 10) > 0)
        // {
        //     num.push_back(x % 10);
        //     x = x / 10;
        // }
        // num.push_back(x);
        // int length = num.size();
        // cout << "length" << length << endl;
        // int mid = int(num.size() / 2);
        // if (num.size() % 2 == 0)
        // {
        //     for (int i = 0; i < (num.size() / 2); i++)
        //     {
        //         if (num[mid - 1 - i] != num[mid + i])
        //         {
        //             return false;
        //         }
        //     }
        //     return true;
        // }
        // else
        // {
        //     for (int i = 0; i <= (num.size() / 2); i++)
        //     {
        //         if (num[mid - i] != num[mid + i])
        //         {
        //             return false;
        //         }
        //     }
        // }
        // return true;
        int revertNumber = 0;
        while (x > revertNumber)
        {
            revertNumber = revertNumber * 10 + x % 10;
            x = x / 10;
        }
        return x == revertNumber || x == revertNumber / 10;
    }

    int lengthOfLongestSubstring(string s)
    {
        map<char, int> romans = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        auto it = s.begin();
        int res = 0;
        while (it != (s.end() - 1))
        {
            if (romans[*it] < romans[*(it + 1)])
            {
                res -= romans[*it];
            }
            else
            {
                res += romans[*it];
            }
            it++;
        }
        return res + romans[*(s.end() - 1)];
    }

    string longestCommonPrefix(vector<string> &strs)
    {
        if (!strs.size())
        {
            return "";
        }
        // 纵向扫描
        // for (int i = 0; i < strs[0].length(); i++)
        // {
        //     char key = strs[0][i];
        //     for (int j = 0; j < strs.size(); j++)
        //     {
        //         if (i == strs[j].length() || strs[j][i] != key)
        //         {
        //             return strs[j].substr(0, i);
        //         }
        //     }
        // }
        // return strs[0];

        // 横向扫描
        // string key = strs[0];

        // for (int i = 1; i < strs.size(); i++)
        // {
        //     key = longestCommonPrefix(key, strs[i]);
        //     if (!key.size())
        //     {
        //         return "";
        //     }
        // }
        // return key;

        // 分治法
        else
        {
            return longestCommonPrefix(strs, 0, strs.size() - 1);
        }
    }

    string CommonPrefix(const string str1, const string str2)
    {
        int length = str1.size() <= str2.size() ? str1.size() : str2.size();
        int i = 0;
        while (i < length && str1[i] == str2[i])
        {
            i++;
        }
        return str1.substr(0, i);
    }

    string longestCommonPrefix(const vector<string> &strs, int start, int end)
    {
        if (start == end)
        {
            return strs[start];
        }
        else
        {
            int mid = (start + end) / 2;
            string lcpLeft = longestCommonPrefix(strs, start, mid);
            string lcpRight = longestCommonPrefix(strs, mid + 1, end);
            return CommonPrefix(lcpLeft, lcpRight);
        }
    }
};

int main()
{

    Solution solution;

    // bool res = solution.isPalindrome(121);
    // int number;
    // cout << "please input a number...\t";
    // cin >> number;
    // // cout << res << endl;
    // if (solution.isPalindrome(number))
    // {
    //     cout << "True!" << endl;
    // }
    // else
    // {
    //     cout << "False!" << endl;
    // }

    vector<string> strs;
    strs.push_back("aaaaaaaa");
    strs.push_back("aaaaaaaa");
    strs.push_back("aaaaaaaa");
    strs.push_back("aaaaaaaa");
    strs.push_back("aaaaaaaa");
    strs.push_back("aaaaaaaa");
    strs.push_back("aaaaaaaa");
    strs.push_back("aaaaaaaa");
    // strings.push_back("gta");
    // strings.push_back("gta");
    // strings.push_back("gta");
    // strings.push_back("avalon");
    // strings.push_back("avalon(2)");
    // strings.push_back("avalon");
    string res = solution.longestCommonPrefix(strs);
}