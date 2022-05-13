/**
 * @file 205.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    char map_t[128]{0};
    char map_s[128]{0};
    for (size_t i = 0; i < s.size(); ++i) {
      if (not map_t[(uint8_t)s[i]]) map_t[(uint8_t)s[i]] = t[i];
      if (not map_s[(uint8_t)t[i]]) map_s[(uint8_t)t[i]] = s[i];
      if (map_t[(uint8_t)s[i]] != t[i] or map_s[(uint8_t)t[i]] != s[i]) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  string s, t;
  while (cin >> s >> t) {
    std::cout << boolalpha << ans.isIsomorphic(s, t) << std::endl;
  }
  return 0;
}
