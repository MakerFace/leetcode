/**
 * @file 481.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-31
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <cstdlib>
#include <string>

#include "common/common.hpp"

using namespace std;

class Solution {
 public:
  int magicalString(int n) {
    int i = 2, j = 3, ans = 1;
    string s;
    s.resize(n);
    s[0] = '1';
    s[1] = '2';
    s[2] = '2';
    auto generate = [&](int m) {
      if (one) {
        for (int i = 0; i < m and j < n; ++i) {
          s[j++] = '1';
          ans++;
        }
      } else {
        for (int i = 0; i < m and j < n; ++i) {
          s[j++] = '2';
        }
      }
      one = !one;
    };
    while (j < n) {
      if (s[i++] == '2') {
        generate(2);
      } else {
        generate(1);
      }
    }
    return ans;
  }

 private:
  bool one = true;
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.31/481.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoi(buf);
    auto ans = sol.magicalString(n);
    std::cout << ans << std::endl;
  }
  return 0;
}
