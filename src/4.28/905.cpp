/**
 * @file 905.cpp
 * @brief 按奇偶排序数组
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-28
 */
#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            while (i < j && !(nums[i] % 2)) // nums[i]是奇数
            {
                ++i;
            }
            while (j > i && nums[j] % 2) // nums[j]是偶数
            {
                --j;
            }
            if (i < j)
            {
                swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }
        return nums;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> nums = {0, 2, 1, 4};
    auto res = ans.sortArrayByParity(nums);
    print_vector(res);
    std::cout << std::endl;
    return 0;
}
