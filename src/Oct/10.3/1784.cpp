/**
 * @file 1784.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-03
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool checkOnesSegment(string s) {
    int i = 0;
    int n = static_cast<int>(s.size());
    while (i < n and s[i] == '1') {
      ++i;
    }
    while (i < n and s[i] == '0') {
      ++i;
    }
    return i >= n;
  }
};

int main(int argc, char const *argv[]) {
  string s;
  Solution sol;
  while (cin >> s) {
    std::cout << boolalpha << sol.checkOnesSegment(s) << std::endl;
  }
  return 0;
}
