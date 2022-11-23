/**
 * @file 6238.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-12
 */
#include <bits/stdc++.h>

#include <cstdlib>

#include "common/Vector.hpp"
using namespace std;

class Solution {
 public:
  int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> dp(high + 1);
    dp[0] = 1;
    for (int i = 1; i <= high; ++i) {
      if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % (1000000007);
      if (i >= one) dp[i] = (dp[i] + dp[i - one]) % (1000000007);
    }
    int ans = 0;
    for (int i = low; i <= high; ++i) {
        ans = (ans + dp[i])%(1000000007);
    }
    
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.12/6238.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto low = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto high = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto zero = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto one = atoi(buf);
    auto ans = sol.countGoodStrings(low, high, zero, one);
    std::cout << ans << std::endl;
  }
  return 0;
}
