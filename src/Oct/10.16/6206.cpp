/**
 * @file 6206.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-16
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  bool sumOfNumberAndReverse(int num) {
    if (num == 0) return true;
    int n = num / 2;
    for (int i = num; i >= n; i--) {
      auto temp = reverse(i);
      if (i + temp == num) return true;
    }
    return false;
  }

 private:
  int reverse(int n) {
    int temp = 0;
    while (n) {
      temp *= 10;
      temp += n % 10;
      n /= 10;
    }
    return temp;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.15/6206.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoi(buf);
    auto ans = sol.sumOfNumberAndReverse(n);
    std::cout << boolalpha << ans << std::endl;
  }
  return 0;
}
