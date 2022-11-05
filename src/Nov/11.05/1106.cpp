/**
 * @file 1106.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-05
 */
#include <bits/stdc++.h>

#include <ios>

#include "common/common.hpp"
using namespace std;

class Solution {
 public:
  bool parseBoolExpr(string expression) {
    bool ans = false;
    if (expression[0] == 't') {
      ans = true;
    } else if (expression[0] == '!') {
      ans = not parseBoolExpr(
          expression.substr(2, expression.size() - 3));  //* !()共三个
    } else if (expression[0] == '&') {
      // &(exp1,exp2)
      //* find false
      ans = true;
      for (int i = 2; i < expression.size();) {
        int left = 0;
        int j = i;
        while (left != 0 or (expression[j] != ',' and expression[j] != ')')) {
          left += int(expression[j] == '(');
          left -= int(expression[j] == ')');
          ++j;
        }
        ans = ans && parseBoolExpr(expression.substr(i, j - i));
        i = j + 1;
        if (not ans) {
          break;
        }
      }
    } else if (expression[0] == '|') {
      // |(exp1,exp2)
      //* find true
      ans = false;
      for (int i = 2; i < expression.size();) {
        int left = 0;
        int j = i;
        while (left != 0 or (expression[j] != ',' and expression[j] != ')')) {
          left += int(expression[j] == '(');
          left -= int(expression[j] == ')');
          ++j;
        }
        ans = ans || parseBoolExpr(expression.substr(i, j - i));
        i = j + 1;
        if (ans) {
          break;
        }
      }
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.05/1106.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    string expression{trim(buf, '"')};
    auto ans = sol.parseBoolExpr(expression);
    std::cout << boolalpha << ans << std::endl;
  }
  return 0;
}
