/**
 * @file 415.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-19
 */
#include <bits/stdc++.h>
#include <string>

#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) {
    string ans;
    ans.resize(max(num1.size(), num2.size()) + 1);
    int sum = 0;
    auto rbegin1 = num1.rbegin();
    auto rbegin2 = num2.rbegin();
    auto rbegin_ans = ans.rbegin();
    for (; rbegin1 != num1.rend() and rbegin2 != num2.rend();
         rbegin1++, rbegin2++, rbegin_ans++) {
      sum += *rbegin1 + *rbegin2 - '0' * 2;
      *rbegin_ans = sum % 10 + '0';
      sum /= 10;
    }

    while (rbegin1 != num1.rend()) {
      sum += *rbegin1 - '0';
      *rbegin_ans = sum % 10 + '0';
      sum /= 10;
      rbegin1++, rbegin_ans++;
    }

    while (rbegin2 != num2.rend()) {
      sum += *rbegin2 - '0';
      *rbegin_ans = sum % 10 + '0';
      sum /= 10;
      rbegin2++, rbegin_ans++;
    }

    while (sum) {
      *rbegin_ans = sum % 10 + '0';
      sum /= 10;
      rbegin_ans++;
    }
    if (rbegin_ans == ans.rend())
      return ans;
    return ans.substr(1, ans.size() - 1);
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.19/415.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    string num1 = buf;
    in.getline(buf, MAX_LINE_SIZE);
    string num2 = buf;
    auto ans = sol.addStrings(num1, num2);
    std::cout << ans << std::endl;
  }
  return 0;
}
