/**
 * @file 396.cpp
 * @brief 旋转函数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-22
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 暴力解超时
 */
class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int max_value = INT_MIN;
        int n = nums.size();
        int first = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            first += i * nums[i];
            sum += nums[i];
        }
        int last = nums.size() - 1;
        for (int i = 0; i < n; ++i)
        {
            first = first + sum - n * nums[last--];
            max_value = max(first, max_value);
        }
        return max_value;
    }
};
// private:
    //* 暴力解超时
    // int F(vector<int> &nums, int k)
    // {
    //     int res = 0;
    //     int i = 0;
    //     for (int j = k; j < nums.size(); ++j, ++i)
    //     {
    //         res += i * nums[j];
    //     }
    //     for (int j = 0; j < k; ++j, ++i)
    //     {
    //         res += i * nums[j];
    //     }
    //     return res;
    // }
// };

int main(int argc, char const *argv[])
{
    vector<int> nums = {4, 3, 2, 6};
    Solution s;
    std::cout << s.maxRotateFunction(nums) << std::endl;
    return 0;
}
