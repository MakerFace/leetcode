/**
 * @file 31.cpp
 * @brief 下一个排列
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size() - 1;
        int j = n;
        while (j >= 0)
        {
            if (not j or nums[j] > nums[j - 1])
                break;
            --j;
        }
        if (j == 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        int idx = j - 1;
        sort(nums.begin() + j, nums.end());
        for (int i = j; i <= n; ++i)
        {
            if (nums[i] > nums[idx])
            {
                swap(nums[i], nums[idx]);
                break;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums = {6, 4, 3, 5, 2, 1};
    Solution ans;
    ans.nextPermutation(nums);
    print_vector(nums);
    std::cout << std::endl;
    return 0;
}
