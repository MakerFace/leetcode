/**
 * @file 883.cpp
 * @brief 三维形体投影面积
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-26
 */
#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int area = 0;
        for (int i = 0; i < n; ++i)
        {
            int yzmax = 0;
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] > 0)
                    ++area;
                yzmax = max(yzmax, grid[i][j]);
            }
            area += yzmax;
        }
        for (int j = 0; j < n; ++j)
        {
            int xzmax = 0;
            for (int i = 0; i < n; ++i)
            {
                xzmax = max(xzmax, grid[i][j]);
            }
            area += xzmax;
        }
        return area;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<vector<int>> grid = {{1, 2}, {3, 4}};
    std::cout << ans.projectionArea(grid) << std::endl;
    return 0;
}
