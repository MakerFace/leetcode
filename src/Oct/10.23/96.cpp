/**
 * @file 96.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-23
 */
#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>

#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    return dp[n];
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.23/96.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoi(buf);
    auto ans = sol.numTrees(n);
    std::cout << ans << std::endl;
  }
  return 0;
}
