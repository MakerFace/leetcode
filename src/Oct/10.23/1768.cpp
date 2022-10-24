/**
 * @file 1768.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-23
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int n1 = static_cast<int>(word1.size());
    int n2 = static_cast<int>(word2.size());
    int s1 = 0, s2 = 0;
    string ans;
    ans.reserve(n1 + n2);
    while (s1 < n1 and s2 < n2) {
      ans.push_back(word1[s1++]);
      ans.push_back(word2[s2++]);
    }
    if (s1 < n1) {
      ans += word1.substr(s1, n1 - s1 + 1);
    }
    if (s2 < n2) {
      ans += word2.substr(s2, n2 - s2 + 2);
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.23/1768.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    string word1 = buf;
    in.getline(buf, MAX_LINE_SIZE);
    string word2 = buf;
    auto ans = sol.mergeAlternately(word1, word2);
    std::cout << ans << std::endl;
  }
  return 0;
}
