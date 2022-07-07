/**
 * @file 953.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-17
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  unordered_map<char, size_t> map;

 public:
  bool isAlienSorted(vector<string>& words, string order) {
    for (size_t i = 0; i < order.size(); ++i) {
      map[order[i]] = i;
    }
    for (size_t i = 1; i < words.size(); ++i) {
      if (not bigger(words[i], words[i - 1])) {
        return false;
      }
    }
    return true;
  }

 private:
  /**
   * @brief w1是否大于w2
   */
  inline bool bigger(const string& w1, const string& w2) {
    size_t i = 0, j = 0;
    while (i < w1.size() and j < w2.size()) {
      if (w1[i] != w2[j]) {
        break;
      }
      ++i, ++j;
    }
    if (i == w1.size() and j == w2.size())
      return true;
    else if (i == w1.size())
      return false;
    else if (j == w2.size())
      return true;
    else
      return map[w1[i]] > map[w2[j]];
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  vector<string> words = {"apple", "app"};
  auto order = "abcdefghijklmnopqrstuvwxyz";
  std::cout << boolalpha << ans.isAlienSorted(words, order) << std::endl;
  return 0;
}
