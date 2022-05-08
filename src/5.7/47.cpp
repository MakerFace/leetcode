/**
 * @file 47.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-07
 */
#include <bits/stdc++.h>
#include "common/Matrix.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        result.push_back(nums);
        vector<int> next = nums;
        next_permutation(next.begin(), next.end());
        while (next != result[0])
        {
            result.push_back(next);
            next_permutation(next.begin(), next.end());
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> nums = {1, 1, 3};
    auto res = ans.permuteUnique(nums);
    print_matrix(res);
    return 0;
}
