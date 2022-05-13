/**
 * @file 171.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int result = 0;

    for (int i = 0; i < columnTitle.size(); ++i) {
      result *= 26;
      result += columnTitle[i] - 'A' + 1;
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  string columnTitle;
  while (cin >> columnTitle) {
    std::cout << ans.titleToNumber(columnTitle) << std::endl;
  }
  return 0;
}
