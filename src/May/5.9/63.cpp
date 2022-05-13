/**
 * @file 63.cpp
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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n);
        dp[0] = obstacleGrid[0][0] == 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (obstacleGrid[i][j])
                {
                    dp[j] = 0;
                    continue;
                }
                if (j > 0 and not obstacleGrid[i][j - 1])
                    dp[j] += dp[j - 1];
            }
        }
        return *(dp.end() - 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    Matrix<int> obstacleGrid = {{1}, {0}}; //, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}};
    std::cout << ans.uniquePathsWithObstacles(obstacleGrid) << std::endl;
    return 0;
}
