/**
 * @file 136.cpp
 * @brief 只出现一次的数字
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-27
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            result ^= nums[i];
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> nums = {4, 1, 2, 1, 2};
    std::cout << ans.singleNumber(nums) << std::endl;
    return 0;
}
