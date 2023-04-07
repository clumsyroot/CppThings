#include <iostream>
#include <vector>
#include <string>
#include <climits>

// using namespace std;
using std::max;
using std::min;
using std::string;
using std::vector;

class Solution
{
public:
    // 杨辉三角 -- 二维数组
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++)
        {
            ans[i].resize(i + 1);
            ans[i][0] = ans[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
    // 杨辉三角 II 返回第 rowIndex 列 -- 滚动数组
    vector<int> getRow(int rowIndex)
    {
        // 滚动数组
        vector<int> pre, cur;
        int idx = 0;
        int front;
        while (idx <= rowIndex)
        {
            cur.resize(idx + 1);
            cur[0] = cur[idx] = 1;
            for (int i = 1; i < idx; i++)
            {
                cur[i] = pre[i - 1] + pre[i];
            }
            pre = cur;
            idx++;
        }
        return cur;
    }

    // 买卖股票的最佳时机
    int maxProfit(vector<int> &prices)
    {
        // int ans = 0, n = prices.size();
        // 暴力求解 超时
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         int cur = prices[j] - prices[i];
        //         if (cur > ans)
        //         {
        //             ans = cur;
        //         }
        //     }
        // }
        // return ans;

        int min_price = INT_MAX, max_profit = 0;
        for (auto &&price : prices)
        {
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
        return max_profit;
    }

    // 验证 回文串
    bool isPalindrome(string s)
    {
        if (s == " " || s == "")
        {
            return true;
        }
        string ans;
        for (int i = 0; i < s.length(); i++)
        {
            char cur = s.at(i);
            if (cur > 'z' || cur < 'a')
            {
                cur = cur + 32;
                if (cur > 'z' || cur < 'a')
                {
                    continue;
                }
                ans.insert(ans.end(), cur);
                continue;
            }
            ans.insert(ans.end(), cur);
        }
        int n = ans.length() - 1;
        for (int i = n; i > -1; i--)
        {
            if (ans.at(i) != ans.at(n - i))
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    solution.isPalindrome("0P");
    return 0;
}