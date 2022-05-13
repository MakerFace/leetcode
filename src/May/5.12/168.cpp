/**
 * @file 168.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

// 26进制
class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string result;
    while (columnNumber) {
      int temp = (columnNumber % 26) - 1;
      columnNumber /= 26;
      if (temp < 0) {
        temp = 25;
        columnNumber -= 1;
      }
      result += temp + 'A';
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main(int argc, char const *argv[]) {
  int n;
  Solution ans;
  while (cin >> n) {
    std::cout << ans.convertToTitle(n) << std::endl;
  }
  return 0;
}
