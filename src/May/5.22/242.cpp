/**
 * @file 242.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-22
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> map;
    for (auto c : s) {
      map[c]++;
    }
    for (auto c : t) {
      map[c]--;
    }
    for (auto m : map) {
      if (m.second != 0) {
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
    std::cout << boolalpha << ans.isAnagram(s, t) << std::endl;
  }
  return 0;
}
