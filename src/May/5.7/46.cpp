/**
 * @file 46.cpp
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = A(nums.size());
        vector<vector<int>> result(n);
        vector<int> next = nums;
        for (int i = 0; i < n; ++i)
        {
            result[i] = next;
            next_permutation(next.begin(), next.end());
        }
        return result;
    }

private:
    int A(int n)
    {
        if (n == 1)
            return 1;
        return n * A(n - 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> nums = {1, 2, 3};
    auto res = ans.permute(nums);
    print_matrix(res);
    return 0;
}
