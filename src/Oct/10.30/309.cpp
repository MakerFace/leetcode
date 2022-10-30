/**
 * @file 309.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-30
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(4));
    dp[0][0] = -prices[0];  //* 买入
    // dp[0][1] = 0;           //* 之前卖出
    // dp[0][2] = 0;           //* 今天卖出
    // dp[0][3] = 0;           //* 冷静期
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0],        //* 无操作
                     max(dp[i - 1][3],    //* 冷静期买入
                         dp[i - 1][1]) -  //* 前天卖出后买入
                         prices[i]);

      dp[i][1] = max(dp[i - 1][1],   //* 前一天就是好几天前卖出
                     dp[i - 1][3]);  //* 刚过冷静期

      dp[i][2] = dp[i - 1][0] +  //* 昨天买入
                 prices[i];      //* 今天卖出

      dp[i][3] = dp[i - 1][2];  //* 昨天卖出
    }
    return max(max(dp[n - 1][2], dp[n - 1][1]),  //* 两次卖出都要算
               dp[n - 1][3]);  // *最后一天的冷静期也可能是最大值
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.30/309.txt");
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
