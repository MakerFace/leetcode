/**
 * @file 1662.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-01
 */
#include <bits/stdc++.h>

#include <cstring>
#include <thread>

#include "common/Vector.hpp"
using namespace std;

class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int i = 0, wi = 0, j = 0, wj = 0;
    int n = word1.size();
    int m = word2.size();
    for (; i < n and j < m;) {
      for (; wi < word1[i].size() and wj < word2[j].size(); ++wi, ++wj) {
        if (word1[i][wi] != word2[j][wj]) {
          return false;
        }
      }
      if (wi == word1[i].size()) {
        ++i;
        wi = 0;
      }
      if (wj == word2[j].size()) {
        ++j;
        wj = 0;
      }
    }
    return i == word1.size() and j == word2.size();
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.01/1662.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto word1 = string2vector<string>(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto word2 = string2vector<string>(buf);
    auto ans = sol.arrayStringsAreEqual(word1, word2);
    std::cout << boolalpha << ans << std::endl;
  }
  return 0;
}
