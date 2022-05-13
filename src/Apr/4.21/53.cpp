/**
 * @file 53.cpp
 * @brief 最大子数组和
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-21
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief dp思想，使用pre保存前面连续数组最大值
 * 如果pre+x>pre，则把当前数加入子数组，否则从n重新开始
 */
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0;
        int maxValue = nums[0];
        for (auto n : nums)
        {
            pre = max(pre + n, n);
            maxValue = max(maxValue, pre);
        }
        return maxValue;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {8, -19, 5, -4, 20};
    std::cout << s.maxSubArray(nums) << std::endl;
    return 0;
}
