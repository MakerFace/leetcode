/**
 * @file 459.cpp
 * @brief 重复的子字符串
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-21
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    size_t l = 1;
    for (size_t i = l; i < s.size() && l < s.size(); i += l) {
      if (s.substr(0, l) != s.substr(i, l)) {
        ++l;
        i = 0;
      }
    }
    return l != s.size();
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::cout << boolalpha << s.repeatedSubstringPattern("aba") << std::endl;
  return 0;
}