/**
 * @file 518.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-26
 */
#include "common/Vector.hpp"
#include <fstream>

using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (auto coin : coins) {
      for (int j = coin; j <= amount; ++j) {
        dp[j] += dp[j - coin];
      }
    }
    return dp[amount];
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.26/518.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto amount = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto coins = string2vector(buf);
    auto ans = sol.change(amount, coins);
    std::cout << ans << std::endl;
  }
  return 0;
}
