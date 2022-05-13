/**
 * @file 56.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-09
 */
#include <bits/stdc++.h>
#include "common/Matrix.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        for (size_t i = 1; i < intervals.size(); ++i)
        {
            if (temp[1] < intervals[i][0])
            {
                result.push_back(temp);
                temp = intervals[i];
            }
            else
            {
                temp[0] = min(temp[0], intervals[i][0]);
                temp[1] = max(temp[1], intervals[i][1]);
            }
        }
        result.push_back(temp);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    Matrix<int> intervals = {{1, 2}, {2, 6}, {8, 10}, {15, 18}};
    auto res = ans.merge(intervals);
    print_matrix(res);
    return 0;
}
