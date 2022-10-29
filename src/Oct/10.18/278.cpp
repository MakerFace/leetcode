/**
 * @file 278.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-18
 */
#include <bits/stdc++.h>
#include <cstdlib>

#include "common/utils.hpp"

using namespace std;

class Solution {

public:
  Solution(int bad = 0) : bad(bad) {}

public:
  int firstBadVersion(int n) {
    int left = 1;
    while (left + 1 < n) {
      int mid = left / 2 + n / 2;
      if (isBadVersion(mid)) {
        n = mid;
      } else {
        left = mid + 1;
      }
    }
    if (isBadVersion(left)) {
      return left;
    }
    return left + 1;
  }

private:
  bool isBadVersion(int n) { return n >= bad; }

private:
  int bad;
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.18/278.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    s = buf;
    auto n = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto b = atoi(buf);
    Solution sol(b);
    auto ans = sol.firstBadVersion(n);
    std::cout << ans << std::endl;
  }
  return 0;
}
