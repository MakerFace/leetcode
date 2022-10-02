/**
 * @file test1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-02
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int commonFactors(int a, int b) {
    int ans = 0;
    int n = min(a, b);
    for (int i = 1; i <= n; i++) {
      if (a % i == 0 and b % i == 0) ++ans;
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  int a, b;
  cin >> a >> b;
  std::cout << sol.commonFactors(a, b) << std::endl;
  return 0;
}
