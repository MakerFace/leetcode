/**
 * @file test2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-02
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxSum(vector<vector<int>>& grid) {
    int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());
    int ans = 0;
    for (int i = 0; i <= n - 3; ++i) {
      for (int j = 0; j <= m - 3; ++j) {
        int sum = grid[i + 1][j + 1];
        for (int k = 0; k < 3; k++) {
          sum += grid[i][j + k] + grid[i + 2][j + k];
        }
        ans = max(ans, sum);
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<vector<int>> grid{{520626, 685427, 788912, 800638, 717251, 683428},
                           {23602, 608915, 697585, 957500, 154778, 209236},
                           {287585, 588801, 818234, 73530, 939116, 252369}};
  std::cout << sol.maxSum(grid) << std::endl;
  return 0;
}
