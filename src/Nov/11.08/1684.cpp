/**
 * @file 1684.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-08
 */
#include <bits/stdc++.h>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    int ans = 0;
    unordered_set<char> set(allowed.begin(), allowed.end());
    for (auto&& word : words) {
      bool flag = true;
      for (auto c : word) {
        if (set.count(c) == 0) {
          flag = false;
          break;
        }
      }
      ans += flag;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.08/1684.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    string allowed = buf;
    in.getline(buf, MAX_LINE_SIZE);
    auto words = string2vector<string>(buf);
    auto ans = sol.countConsistentStrings(allowed, words);
    std::cout << ans << std::endl;
  }
  return 0;
}
