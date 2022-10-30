/**
 * @file 123.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-29
 */
#include <fstream>
#include <functional>
#include <queue>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(5));
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);  // 买入股票
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);  // 卖出股票
      dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);  // 买入股票
      dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);  // 买入股票
    }
    return dp[n - 1][4];
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.29/123.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto prices = string2vector(buf);
    auto ans = sol.maxProfit(prices);
    std::cout << ans << std::endl;
  }
  return 0;
}
