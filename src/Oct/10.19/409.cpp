/**
 * @file 409.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-19
 */
#include <bits/stdc++.h>
#include <unordered_map>

#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> map;
    for (auto &c : s) {
      map[c]++;
    }
    int ans = 0;
    int flag = 0;
    for (auto &s : map) {
      auto temp = s.second;
      ans += temp / 2 * 2;
      if (temp % 2) {
        flag = 1;
      }
    }
    return ans + flag;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.19/409.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto ans = sol.longestPalindrome(s);
    std::cout << ans << std::endl;
  }
  return 0;
}
