/**
 * @file 326.cpp
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
  bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    int ans = log10(n) / log10(3);
    return pow(3, ans) == n;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.23/326.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoi(buf);
    auto ans = sol.isPowerOfThree(n);
    std::cout << boolalpha << ans << std::endl;
  }
  return 0;
}
