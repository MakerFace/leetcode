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

    for (int j = 0; j < words.size(); ++j) {
      auto word = words[j];
      int i = 0;
      array<int, 26> idx{0};
      int cur_idx = -1;
      for (; i < word.size(); ++i) {
        if (map.count(word[i]) == 0) {
          break;
        }
        auto iter = lower_bound(map[word[i]].begin() + idx[word[i] - 'a'],
                                map[word[i]].end(), i) -
                    map[word[i]].begin();
        if (iter >= map[word[i]].size()) {
          break;
        }
        if (map[word[i] - 'a'][iter] < cur_idx) {
          cur_idx = ;
        }
        idx[word[i] - 'a']++;
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
