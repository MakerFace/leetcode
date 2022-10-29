/**
 * @file 290.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-20
 */
#include <bits/stdc++.h>
#include <ios>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> map;
    stringstream ss(s);
    string word;
    int idx = 0;
    int psize = static_cast<int>(pattern.size());
    while (ss >> word) {
      if (idx >= psize) {
        return false;
      }
      if (map.count(pattern[idx]) == 0) {
        map[pattern[idx]] = std::move(word);
      } else if (map[pattern[idx]] != word) {
        return false;
      }
      ++idx;
    }
    if (idx < psize) {
      return false;
    }
    unordered_set<string> word_set;
    for (auto &w : map) {
      word_set.insert(std::move(w.second));
    }
    return word_set.size() == map.size();
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.20/290.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto pattern = s;
    in.getline(buf, MAX_LINE_SIZE);
    s = buf;
    auto ans = sol.wordPattern(pattern, s);
    std::cout << boolalpha << ans << std::endl;
  }
  return 0;
}
