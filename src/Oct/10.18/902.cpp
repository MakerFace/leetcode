/**
 * @file 902.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-18
 */
#include <array>
#include <bits/stdc++.h>
#include <cstdlib>

#include "common/Vector.hpp"
#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  int atMostNGivenDigitSet(vector<string> &digits, int n) {
    string s = to_string(n);
    int m = digits.size(), k = s.size();
    vector<vector<int>> dp(k + 1, vector<int>(2));
    dp[0][1] = 1;
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j < m; j++) {
        if (digits[j][0] == s[i - 1]) {
          dp[i][1] = dp[i - 1][1];
        } else if (digits[j][0] < s[i - 1]) {
          dp[i][0] += dp[i - 1][1];
        } else {
          break;
        }
      }
      if (i > 1) {
        dp[i][0] += m + dp[i - 1][0] * m;
      }
    }
    return dp[k][0] + dp[k][1];
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.18/902.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto digits = string2vector<string>(s);
    in.getline(buf, MAX_LINE_SIZE);
    auto n = atoi(buf);
    auto ans = sol.atMostNGivenDigitSet(digits, n);
    std::cout << ans << std::endl;
  }
  return 0;
}
