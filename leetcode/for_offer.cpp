#include <string>
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
};