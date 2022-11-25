/**
 * @file 809.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-25
 */
#include <bits/stdc++.h>

#include <utility>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int expressiveWords(string s, vector<string>& words) {
    int ans = 0;
    vector<pair<char, int>> s_size;
    int l = 0, r = 0;
    while (r < s.size()) {
      while (r < s.size() and s[r] == s[l]) ++r;
      s_size.emplace_back(make_pair(s[l], r - l));
      l = r;
    }
    for (auto&& word : words) {
      l = 0, r = 0;
      int idx = 0;
      while (idx < s_size.size() and r < word.size()) {
        while (r < word.size() and word[r] == word[l]) ++r;
        if (word[l] != s_size[idx].first) {
          break;
        }
        if (r - l < s_size[idx].second) {
          if (s_size[idx].second < 3) {
            break;
          }
        } else if (r - l > s_size[idx].second) {
          break;
        }
        l = r;
        ++idx;
      }
      ans += (r == word.size() and idx == s_size.size());
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.25/809.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    in.getline(buf, MAX_LINE_SIZE);
    auto words = string2vector<string>(buf);
    auto ans = sol.expressiveWords(s, words);
    std::cout << ans << std::endl;
  }
  return 0;
}
