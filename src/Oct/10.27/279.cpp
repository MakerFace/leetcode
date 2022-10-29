/**
 * @file 279.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-27
 */
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    for (int j = 1; j <= n; ++j) {
      int minn = dp[j];
      for (int i = 1; i*i <= j; ++i) {
        minn = min(minn, dp[j - i * i]);
      }
      dp[j] = minn + 1;
    }
    sort(dp.begin(), dp.end());
    return dp[n];
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.27/279.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoi(buf);
    auto ans = sol.numSquares(n);
    std::cout << ans << std::endl;
  }
  return 0;
}
