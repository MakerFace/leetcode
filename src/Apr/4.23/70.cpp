/**
 * @file 70.cpp
 * @brief 爬楼梯
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-23
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    int f[4] = {0};
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; ++i) {
      f[0] = f[2];
      f[2] = f[1] + f[3];
      f[1] = f[0];
    }
    if (n == 1) return f[1];
    return f[2];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::cout << s.climbStairs(45) << std::endl;
  return 0;
}
