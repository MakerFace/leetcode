/**
 * @file 1767.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    string merged;
    size_t i = 0;
    size_t j = 0;
    while (i < word1.size() and j < word2.size()) {
      merged += word1[i++];
      merged += word2[j++];
    }
    while (i < word1.size()) {
      merged += word1[i++];
    }
    while (j < word2.size()) {
      merged += word2[j++];
    }
    return merged;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  string word1, word2;
  while (cin >> word1 >> word2) {
    std::cout << ans.mergeAlternately(word1, word2) << std::endl;
  }
  return 0;
}
