#include <iostream>
#include <vector>

// using namespace std;
using std::vector;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++)
        {
            ans[i].resize(i);
        }
    }
};

int main()
{

    return 0;
}