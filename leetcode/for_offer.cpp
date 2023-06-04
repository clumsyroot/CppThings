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
        
    }
};