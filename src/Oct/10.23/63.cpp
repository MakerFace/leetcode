/**
 * @file 63.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-23
 */
#include <bits/stdc++.h>
#include <vector>

#include "common/Matrix.hpp"
#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = static_cast<int>(obstacleGrid.size());
    int n = static_cast<int>(obstacleGrid[0].size());
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = obstacleGrid[0][0] == 0;
    for (int j = 2; j <= n; ++j) {
      if (not obstacleGrid[0][j - 1])
        dp[j] = dp[j - 1];
    }
    std::cout << dp << std::endl;
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (obstacleGrid[i][j - 1]) {
          dp[j] = 0;
          continue;
        }
        dp[j] += dp[j - 1];
      }
      std::cout << dp << std::endl;
    }
    return dp[n];
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.23/63.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto obstacleGrid = string2matrix(buf);
    auto ans = sol.uniquePathsWithObstacles(obstacleGrid);
    std::cout << ans << std::endl;
  }
  return 0;
}
