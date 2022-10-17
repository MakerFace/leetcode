/**
 * @file 940.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-14
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  int distinctSubseqII(string s) {
    array<int, 26> dp{0};
    for (auto c : s) {
      dp[c-'a']=accumulate(dp.begin(), dp.end(), 1LL) % (1000000007);
    }
    return accumulate(dp.begin(), dp.end(), 0LL) % 1000000007;   
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.14/940.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto ans = sol.distinctSubseqII(s);
    std::cout << ans << std::endl;
  }
  return 0;
}
