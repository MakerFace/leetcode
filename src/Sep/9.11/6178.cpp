/**
 * @file 6178.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-11
 */

#include <bits/stdc++.h>

#include "common/Matrix.hpp"
using namespace std;

class Solution {
  int cnt[100000]{0};

 public:
  /**
   * @brief 扫描线算法，经典题目：数飞机
   */
  int minGroups(vector<vector<int>>& intervals) {
    for (auto& i : intervals) {
      cnt[i[0]]++;
      cnt[i[1] + 1]--;
    }
    int ans = 0;
    int count = 0;
    for (int i = 0; i < 100000; i++) {
      count += cnt[i];
      ans = max(ans, count);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  Matrix<int> intervals = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
  std::cout << sol.minGroups(intervals) << std::endl;
  return 0;
}
