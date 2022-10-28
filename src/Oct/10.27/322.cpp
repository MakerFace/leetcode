/**
 * @file 322.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-27
 */
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
    if (not amount) return 0;
    vector<long long> dp(amount + 1, amount + 1);
    dp[0] = 1;
    for (auto coin : coins) {
      if (coin > amount) {
        continue;
      }
      dp[coin] = 1;
      for (int j = coin + 1; j <= amount; ++j) {
        dp[j] = min(dp[j], dp[j - coin] + dp[coin]);
      }
    }
    return dp[amount] < amount + 1 ? dp[amount] : -1;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.27/322.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto coins = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto amount = atoi(buf);
    auto ans = sol.coinChange(coins, amount);
    std::cout << ans << std::endl;
  }
  return 0;
}
