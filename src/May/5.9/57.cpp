/**
 * @file 57.cpp
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
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        if (intervals.empty())
            return vector<vector<int>>(1, newInterval);
        int i = 0, j = intervals.size() - 1;
        int mid;
        while (i <= j)
        {
            mid = (i + j) / 2;
            if (intervals[mid][0] == newInterval[0])
            {
                break;
            }
            else if (intervals[mid][0] > newInterval[0])
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        if (intervals[mid][0] >= newInterval[0])
            intervals.insert(intervals.begin() + mid, 1, newInterval);
        else
            intervals.insert(intervals.begin() + mid + 1, 1, newInterval);
        return merge(intervals);
    }

private:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
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
    Matrix<int> intervals = {{1, 5}};
    vector<int> newInterval = {6, 13};
    auto res = ans.insert(intervals, newInterval);
    print_matrix(res);
    return 0;
}
