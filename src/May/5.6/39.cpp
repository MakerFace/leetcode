/**
 * @file 39.cpp
 * @brief 组合总和
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
#include "common/Matrix.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        return vector<vector<int>>();
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    auto res = ans.combinationSum(candidates, target);
    print_matrix(res);
    return 0;
}
