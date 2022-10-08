/**
 * @file 5.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-06
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  /**
   * @brief 不要用ans暂存答案，用left+length存索引
   */
  string longestPalindrome(string s) {
    int n = static_cast<int>(s.length());
    int left = 0, length = 0;
    auto hasPalindrome = [&s](int i, int j, int n) {
      int k = i - 1, l = j + 1;
      while (k >= 0 and l < n) {
        if (s[k] != s[l]) break;
        --k, ++l;
      }
      return l - k - 1;  // (l-1) - (k+1) + 1
    };
    for (int i = 0; i < n; ++i) {
      auto len = hasPalindrome(i, i, n);
      if (len > length) {
        length = len;
        left = i - len / 2;
      }
      if (i + 1 < n and s[i] == s[i + 1]) {
        len = hasPalindrome(i, i + 1, n);
        if (len > length) {
          length = len;
          left = i - len / 2 + 1;
        }
      }
    }
    return s.substr(left, length);
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string s;
  while (cin >> s) {
    std::cout << sol.longestPalindrome(s) << std::endl;
  }

  return 0;
}