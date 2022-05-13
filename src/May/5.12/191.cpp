/**
 * @file 191.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief n&(n-1), 每次将最后一位1变为0
 */
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int result = 0;
    // while (n) {
    //   if (n & 1) ++result;
    //   n >>= 1;
    // }
    while (n) {
      n &= n - 1;
      ++result;
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  uint32_t n;
  while (cin >> n) {
    std::cout << ans.hammingWeight(n) << std::endl;
  }
  return 0;
}
