/**
 * @file 6195.cpp
 * @brief 字符串的双值哈希
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-02
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int deleteString(string s) {
    unordered_map<string, int> map;
    int i = 0, len = 0;
    int n = static_cast<int>(s.size());
    for (int j = 0; j < n; ++j) {
      if (s[i + len] == s[j]) {
        ++len;
      } else {
        map[s.substr(0, len)] = len;
        len = 0;
      }
    }
    return 0;
  }
};

int main(int argc, char const *argv[]) {
  string s;
  Solution sol;
  while (cin >> s) {
    std::cout << sol.deleteString(s) << std::endl;
  }
  return 0;
}
