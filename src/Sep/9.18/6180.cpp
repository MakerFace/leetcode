/**
 * @file 6180.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-18
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int smallestEvenMultiple(int n) {
    if (not (n % 2))
      return n;
    else
      return n * 2;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  int n;
  while (cin >> n) {
    std::cout << sol.smallestEvenMultiple(n) << std::endl;
  }
  return 0;
}
