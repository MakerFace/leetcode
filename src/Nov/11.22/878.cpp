/**
 * @file 878.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-22
 */
#include <bits/stdc++.h>

#include <cassert>
#include <cstdlib>
#include <numeric>

using namespace std;

class Solution {
 public:
  int nthMagicalNumber(int n, int a, int b) {
    long long ans = 0;
    auto lcm = std::lcm(a, b);
    long long left = 1, right = (long long)n * max(a, b);
    while (left <= right) {
      auto mid = (left + right) / 2;
      assert(a != 0 && b != 0 && lcm != 0);
      //* f(x) = ⌊x/a⌋ + ⌊x/b⌋ - ⌊x/lcm⌋
      //* 可以计算出小于等于x的数中有多少个可以被a,b整除的。
      auto temp = (mid / a) + (mid / b) - (mid / lcm);
      if (temp == n && (mid % a == 0 or mid % b == 0)) {
        return (mid % 1000000007);
      } else if (temp < n) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.22/878.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto a = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto b = atoi(buf);
    auto ans = sol.nthMagicalNumber(n, a, b);
    std::cout << ans << std::endl;
  }
  return 0;
}
