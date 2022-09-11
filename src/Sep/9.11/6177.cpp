/**
 * @file 6177.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-11
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int partitionString(string s) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n;) {
      unordered_set<char> set;
      auto res = set.insert(s[i]);
      while (i < n and res.second) {
        ++i;
        res = set.insert(s[i]);
      }
      ++ans;
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  string s;
  Solution sol;
  while (cin >> s) {
    std::cout << sol.partitionString(s) << std::endl;
  }
  return 0;
}
