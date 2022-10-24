/**
 * @file 62.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-23
 */
#include <bits/stdc++.h>
#include <cstdlib>

#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<int> dp(n + 1, 1);
    dp[0] = 0;
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[j] += dp[j - 1];
      }
    }
    return dp[n];
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.23/62.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto m = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto n = atoi(buf);
    auto ans = sol.uniquePaths(m, n);
    std::cout << ans << std::endl;
  }
  return 0;
}
