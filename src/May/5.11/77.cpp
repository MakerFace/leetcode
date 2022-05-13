/**
 * @file 77.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-11
 */
#include <bits/stdc++.h>

#include "common/Matrix.hpp"
using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> s(k);
    vector<vector<int>> result(c(n, k));
    // size_t top = k - 1;
    // size_t j = k;
    for (int i = 1; i <= k; ++i) s[i - 1] = i;

    for (size_t cur = 0; cur < result.size(); ++cur) {
      result[cur] = s;
      if (s[k - 1] >= n) {
        for (size_t i = k - 1; i > 0; --i) {
          if (s[i] - s[i - 1] > 1) {
            s[i - 1]++;
            for (int j = i; j < k; ++j) {
              s[j] = s[j - 1] + 1;
            }
            break;
          }
        }
      } else {
        ++s[k - 1];
      }
    }
    return result;
  }

 private:
  int c(int n, int m) {
    if (m > n / 2) {
      m = n - m;
    }
    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = min(i, m); j >= 0; --j) {
        if (i == j or j == 0)
          dp[j] = 1;
        else
          dp[j] += dp[j - 1];
      }
    }
    return dp[m];
  }
};

int main(int argc, char const *argv[]) {
  int n, k;
  Solution ans;
  while (cin >> n >> k) {
    auto res = ans.combine(n, k);
    print_matrix(res);
    std::cout << std::endl;
  }
  return 0;
}
