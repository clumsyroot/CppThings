#include <iostream>
#include <vector>

// using namespace std;
using std::vector;

class Solution
{
public:
    // 杨辉三角
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
    // 杨辉三角 II 返回第 rowIndex 列
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
};

int main()
{
    Solution solution;
    solution.getRow(3);
    return 0;
}