/**
 * @file ms01.09.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-29
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isFlipedString(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    s2 += s2;
    auto found = search(s2.begin(), s2.end(), s1.begin(), s1.end());
    return found != s2.end();
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string s1{"abcd"}, s2{"cdab"};
  std::cout << boolalpha << sol.isFlipedString(s1, s2) << std::endl;
  return 0;
}
