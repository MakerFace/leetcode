/**
 * @file 231.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }

    n &= n - 1;
    return n == 0;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  int n;
  while (cin >> n) {
    std::cout << boolalpha << ans.isPowerOfTwo(n) << std::endl;
  }

  return 0;
}
