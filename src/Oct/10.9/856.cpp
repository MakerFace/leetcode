/**
 * @file 856.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-09
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  int scoreOfParentheses(string s) { return recursive(s.begin(), s.end()); }

 private:
  int recursive(string::iterator first, string::iterator last) {
    if (first + 2 == last) return 1;
    if (*first != '(') return 0;
    int left = 0;
    int right = 0;
    auto iter = first;
    do {
      if (*iter == '(')
        ++left;
      else
        ++right;
      ++iter;
    } while (left != right and iter < last);
    if (left >= 2) {
      left = 2 * recursive(first + 1, iter);
      right = recursive(iter, last);
    } else {
      // left;
      right = recursive(iter, last);
    }
    return left + right;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string s = string(PROJECT_PATH).append("/src/Oct/10.9/856.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    s = buf;
    auto ans = sol.scoreOfParentheses(s);
    std::cout << ans << std::endl;
  }
  return 0;
}
