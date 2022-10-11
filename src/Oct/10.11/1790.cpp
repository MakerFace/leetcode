/**
 * @file 1790.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-11
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  bool areAlmostEqual(string s1, string s2) {
    int n = static_cast<int>(s1.length());
    bool flag = false;
    int first = -1;
    for (int i = 0; i < n; ++i) {
      if (s1[i] != s2[i]) {
        if (first == -1)
          first = i;
        else {
          if (flag) return false;
          if (s1[first] != s2[i] or s1[i] != s2[first]) return false;
          swap(s1[first], s2[i]);
          flag = true;
        }
      }
    }
    if (first == -1) return true;
    return s1[first] != s2[first];
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string s = string(PROJECT_PATH).append("/src/Oct/10.11/1790.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    s = buf;
    in.getline(buf, MAX_LINE_SIZE);
    string s1(buf);
    auto ans = sol.areAlmostEqual(s, s1);
    std::cout << boolalpha << ans << std::endl;
  }
  return 0;
}
