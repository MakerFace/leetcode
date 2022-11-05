/**
 * @file 1668.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-03
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

#include "common/Vector.hpp"
using namespace std;

class Solution {
 public:
  int maxRepeating(string sequence, string word) {
    if (word.size() > sequence.size()) {
      return 0;
    }
    vector<int> next(word.size(), -1);
    //? 这不是KMP算法吧
    for (int i = 1; i < word.size(); ++i) {
      int j = next[i - 1];
      while (j != -1 && word[j + 1] != word[i]) {
        j = next[j];
      }
      if (word[j + 1] == word[i]) {
        next[i] = j + 1;
      }
    }
    vector<int> dp(sequence.size());
    int i = -1;
    for (int j = 0; j < sequence.size(); ++j) {
      while (i != -1 and word[i + 1] != sequence[j]) {
        i = next[i];
      }
      if (word[i + 1] == sequence[j]) {
        ++i;
        if (i + 1 == word.size()) {
          dp[j] = (j >= word.size() ? dp[j - word.size()] : 0) + 1;
          i = next[i];
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.03/1668.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    string sequence(buf);
    in.getline(buf, MAX_LINE_SIZE);
    string word(buf);
    auto ans = sol.maxRepeating(sequence, word);
    std::cout << ans << std::endl;
  }
  return 0;
}
