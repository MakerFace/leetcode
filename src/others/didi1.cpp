/**
 * @file didi1.cpp
 * @brief 离散化+扫描线
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-17
 */

// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, p, q;
  cin >> n >> p >> q;
  vector<vector<int>> nums(3, vector<int>(n));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      cin >> nums[i][j];
    }
  }

  vector<tuple<int, int, int, int>> sweep;
  for (int i = 0; i < n; i++) {
    sweep.emplace_back(nums[0][i], nums[2][i], i, 1);   // l
    sweep.emplace_back(nums[1][i], nums[2][i], i, -1);  // r
  }
  sort(sweep.begin(), sweep.end());

  auto len = static_cast<int>(sweep.size());

  int color[3] = {0};
  int ans = 0;
  bool find = false;
  int prev_range = 0;
  for (int i = 0; i < len;) {
    int j = i;
    int range, col_idx, nums_idx, diff;
    while (j < len and get<0>(sweep[j]) == get<0>(sweep[i])) {
      tie(range, col_idx, nums_idx, diff) = sweep[j];
      color[col_idx] += diff;
      ++j;
    }
    if (color[1] >= p and color[2] >= q) {
      if (not find) {
        find = true;
        prev_range = range;
      }
    } else if (find) {
      ans += range - prev_range + 1;
      find = false;
    }
    i = j;
  }
  cout << ans << endl;
  return 0;
}
