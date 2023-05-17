#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        // vector<string> ans;
        // if (nums.empty()) return nullptr;
        // int n = nums.size();
        // string pre = to_string(nums[0]);
        // string cur;
        // int count = 1;
        // for (int i = 1; i < n; i++)
        // {
        //     if (nums[i] == nums[i - 1] + 1) // nums[i] - nums[i-1] == 1 会溢出！！！
        //     {
        //         count++;
        //         continue;
        //     };
        //     if (count > 1)
        //     {
        //         cur = pre + "->" + to_string(nums[i - 1]);
        //     }
        //     else
        //     {
        //         cur = to_string(nums[i - 1]);
        //     }
        //     ans.emplace_back(cur);
        //     pre = to_string(nums[i]);
        //     count = 1;
        // }
        // if (count > 1)
        // {
        //     cur = pre + "->" + to_string(nums[n - 1]);
        // }
        // else
        // {
        //     cur = pre;
        // }
        // ans.emplace_back(cur);

        // return ans;

        // 与上面思路一样，但更加优雅！
        vector<string> ans;
        int i = 0;
        int n = nums.size();
        while (i < n)
        {
            int low = i;
            i++;
            while (i < n && nums[i] == nums[i - 1] + 1)
            {
                i++;
            }
            int high = i - 1;
            string cur = to_string(nums[low]);
            if (low < high)
            {
                cur = cur + "->" + to_string(nums[high]);
            }
            ans.emplace_back(cur);
        }
        return ans;
    }
};

int main()
{
    using namespace std;
    vector<int> test = {0, 1, 2, 4, 5, 7};
    Solution solution;
    solution.summaryRanges(test);

    return 0;
}