/**
 * @file 121.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-29
 */
#include <climits>
#include <fstream>
#include <stack>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int min_price = INT_MAX;
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      min_price = min(min_price, prices[i]);
      dp[i + 1] = max(dp[i], prices[i] - min_price);
    }
    return dp[n];
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.29/121.txt");
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
