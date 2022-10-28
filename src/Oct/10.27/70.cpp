/**
 * @file 70.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-27
 */
#include "common/Vector.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int j = 1; j <= n; ++j) {
      for (int i = 1; i <= 2; ++i) {
        if (j - i >= 0) {
          dp[j] += dp[j - i];
        }
      }
      std::cout << dp << std::endl;
    }
    return dp[n];
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.27/70.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoi(buf);
    auto ans = sol.climbStairs(n);
    std::cout << ans << std::endl;
  }
  return 0;
}
