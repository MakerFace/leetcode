/**
 * @file 667.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-08
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  vector<int> constructArray(int n, int k) {
    vector<int> ans(n);
    int start = 1, end = k + 1;
    int mid = end + 1;
    // TODO 至少2个数
    int i = 0;
    while (start < end) {
      ans[i++] = start++;
      ans[i++] = end--;
    }
    if (k % 2 == 0) {
      ans[i++] = start;
    }

    while (mid <= n) {
      ans[i++] = mid;
      ++mid;
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  int n, k;
  while (cin >> n >> k) {
    auto ans = sol.constructArray(n, k);
    println_vector(ans);
  }
  return 0;
}
