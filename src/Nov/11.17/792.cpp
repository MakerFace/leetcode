/**
 * @file 792.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-17
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <unordered_map>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int numMatchingSubseq(string s, vector<string>& words) {
    int ans = 0;
    unordered_map<char, vector<int>> map;
    for (int i = 0; i < s.size(); ++i) {
      map[s[i]].push_back(i);
    }

    for (auto&& word : words) {
      int i = 0;
      for (; i < word.size(); ++i) {
        auto iter =
            lower_bound(map[word[i]].begin() + i, map[word[i]].end(), i);
        if (iter == map[word[i]].end()) {
          break;
        }
      }
      ans += i == word.size();
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.17/792.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    in.getline(buf, MAX_LINE_SIZE);
    auto words = string2vector<string>(buf);
    auto ans = sol.numMatchingSubseq(s, words);
    std::cout << ans << std::endl;
  }
  return 0;
}
