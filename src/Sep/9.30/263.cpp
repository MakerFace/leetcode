/**
 * @file 263.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-30
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isUgly(int n) {
    if (n <= 0) return false;
    for (auto t : table) {
      while (n % t == 0) {
        n /= t;
      }
    }
    return n == 1;
  }

 private:
  vector<int> table{2, 3, 5};
};

int main(int argc, char const *argv[]) {
  int n = 0;
  Solution sol;
  while (cin >> n) {
    std::cout << boolalpha << sol.isUgly(n) << std::endl;
  }
  return 0;
}
