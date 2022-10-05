/**
 * @file 921.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-04
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minAddToMakeValid(string s) {
    stack<char> sta;
    for (auto &c : s) {
      if (c == ')') {
        if (sta.empty())
          sta.push(c);
        else if (sta.top() == '(')
          sta.pop();
        else
          sta.push(c);
      } else {
        sta.push(c);
      }
    }
    return sta.size();
  }
};

int main(int argc, char const *argv[]) {
  string s;
  Solution sol;
  while (cin >> s) {
    std::cout << sol.minAddToMakeValid(s) << std::endl;
  }

  return 0;
}
