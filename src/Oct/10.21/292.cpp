/**
 * @file 292.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-21
 */
#include <bits/stdc++.h>
#include <cstdlib>
#include <ios>

#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  bool canWinNim(int n) {
    return n % 4 != 0;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.21/292.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoi(buf);
    auto ans = sol.canWinNim(n);
    std::cout << boolalpha << ans << std::endl;
  }
  return 0;
}
