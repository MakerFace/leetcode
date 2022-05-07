/**
 * @file 1752.cpp
 * @brief 检查数组是否经排序和轮转得到
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int p = i;
            int q;
            int j;
            for (j = 0; j < n - 1; ++j)
            {
                q = p;
                p++;
                p %= n;
                if (nums[p] < nums[q])
                {
                    break;
                }
            }
            if (j == n - 1)
                return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> nums = {1, 3, 4};
    std::cout << boolalpha << ans.check(nums) << std::endl;
    return 0;
}
