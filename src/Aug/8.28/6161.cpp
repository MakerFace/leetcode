/**
 * @file 6161.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-08-28
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string removeStars(string s) {
    string ans;
    ans.resize(s.length());
    int n = 0;
    for (size_t i = 0; i < s.length(); ++i) {
      if (s[i] == '*') {
        --n;
      } else {
        ans[n] = s[i];
        ++n;
      }
    }
    ans.resize(n);
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  auto s = "abb*cdfg*****x*";
  Solution sol;
  cout << sol.removeStars(s) << endl;
  return 0;
}
