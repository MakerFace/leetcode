/**
 * @file 338.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-23
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; ++i) {
      auto t = i;
      while (t) {
        ans[i] += t & 0x1;
        t >>= 1;
      }
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.23/338.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoi(buf);
    auto ans = sol.countBits(n);
    std::cout << ans << std::endl;
  }
  return 0;
}
