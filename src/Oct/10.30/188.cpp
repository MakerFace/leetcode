/**
 * @file 188.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-30
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2 * k + 1));
    for (int i = 0; i < k; ++i) {
      dp[0][2 * i + 1] = -prices[0];
    }
    std::cout << dp[0] << std::endl;
    for (int i = 1; i < n; ++i) {
      dp[i][0] = dp[i - 1][0];
      for (int j = 0; j < k; ++j) {
        dp[i][2 * j + 1] =
            max(dp[i - 1][2 * j + 1], dp[i - 1][2 * j] - prices[i]);
        dp[i][2 * j + 2] =
            max(dp[i - 1][2 * j + 2], dp[i - 1][2 * j + 1] + prices[i]);
      }
      std::cout << dp[i] << std::endl;
    }
    return dp[n - 1][2 * k];
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.30/188.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto k = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto prices = string2vector(buf);
    auto ans = sol.maxProfit(k, prices);
    std::cout << ans << std::endl;
  }
  return 0;
}
