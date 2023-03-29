#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // 小数转二进制
    string printBin(double num)
    {
        string res = "0.";
        while (res.size() <= 32 && num != 0)
        {
            num *= 2;
            int digit = num;
            // c++: char 在运算中会转换成 ASCII 参与运算
            res.push_back(digit + '0');
            num -= digit;
        }
        return res.size() <= 32 ? res : "ERROR";
    }

    // 保证文件名唯一
    string addSuffix(string name, int k)
    {
        return name + "(" + to_string(k) + ")";
    }

    vector<string> getFolderNames(vector<string> &names)
    {
        unordered_map<string, int> name_idx;
        vector<string> res;
        for (int i = 0; i < names.size(); i++)
        {
            string name = names.at(i);
            if (!name_idx.count(name))
            {
                res.push_back(name);
                name_idx[name] = 1;
            }
            else
            {
                int k = name_idx[name];
                while (name_idx.count(addSuffix(name, k)))
                {
                    k++;
                }
                res.push_back(addSuffix(name, k));
                name_idx[name] = k + 1; // 减小查询开销
                name_idx[addSuffix(name, k)] = 1;
            }
        }
        return res;
    }

    // 使整数组可以被 p 整除
    // int minSubarray(vector<int> &nums, int p)
    // {
    //     for (auto num : nums)
    //     {
    //     }
    // }

    // 两数之和
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int low, high, mid;
        vector<int> res;
        // low = 0;
        high = nums.size();
        // 快速排序
        // for (int i = 0; i < high; i++)
        // {
        //     int key = target - nums[i];
        //     while (low <= high)
        //     {
        //         mid = (low + high) / 2;
        //         if (key < nums[mid])
        //         {
        //             high = mid - 1;
        //         }
        //         else if (key > nums[mid])
        //         {
        //             low = mid + 1;
        //         }
        //         else
        //         {
        //             res.push_back(i);
        //             res.push_back(mid);
        //             return res;
        //         }
        //     }
        // }
        // 暴力查找
        // for (int i = 0; i < high; i++)
        // {
        //     int key = target - nums[i];
        //     for (int j = 0; j < high; j++)
        //     {
        //         if (key == nums[j] & i != j)
        //         {
        //             res.push_back(i);
        //             res.push_back(j);
        //             return res;
        //         }
        //     }
        // }
        // 哈希表
        unordered_map<int, int> map;
        for (int i = 0; i < high; i++)
        {
            // 找不到返回Map最后一个位置的后一位
            auto key = map.find(target - nums[i]);
            if (key != map.end())
            {
                // (key, value) first - value, second - key
                return {key->second, i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    // double number;
    // cout << "input number" << endl;
    // cin >> number;

    Solution solution;
    // // cout << solution.printBin(number) << endl;

    // vector<string> names;
    // names.push_back("gta");
    // names.push_back("gta");
    // names.push_back("gta");
    // names.push_back("gta");
    // names.push_back("avalon");
    // names.push_back("avalon(2)");
    // names.push_back("avalon");

    // vector<string> res = solution.getFolderNames(names);

    // for (auto name : res)
    // {
    //     cout << name << endl;
    // }

    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;

    vector<int> res = solution.twoSum(nums, target);
    for (auto num : res)
    {
        cout << num << endl;
    }
}