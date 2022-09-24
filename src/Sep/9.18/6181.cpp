/**
 * @file 6180.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-18
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int longestContinuousSubstring(string s) {
    int ans = 0;
    int len = 0;
    int n = s.size();
    int i = 0, j = 0;
    while (j < n) {
      if (j > 0 and s[j] != s[j - 1] + 1) {
        len = 0;
      }
      len++;
      ans = max(ans, len);
      j++;
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string n;
  while (cin >> n) {
    std::cout << sol.longestContinuousSubstring(n) << std::endl;
  }
  return 0;
}
