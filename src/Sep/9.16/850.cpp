/**
 * @file 850.cpp
 * @brief 矩形面积总和
 * 离散化+扫描线+简单数组（时间复杂度O(n^2))
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-16
 */

#include <bits/stdc++.h>

#include "common/Matrix.hpp"
using namespace std;

class Solution {
 public:
  int rectangleArea(vector<vector<int>>& rectangles) {
    int n = rectangles.size();
    vector<int> hbound;
    for (auto& rect : rectangles) {  // 离散化Y轴，端点值
      hbound.push_back(rect[1]);
      hbound.push_back(rect[3]);
    }
    sort(hbound.begin(), hbound.end());
    hbound.erase(unique(hbound.begin(), hbound.end()),
                 hbound.end());  // 移除连续重复的区间端点
    int m = hbound.size();       // 区间端点个数
    vector<int> seg(m - 1);
    vector<tuple<int, int, int>> sweep;  // X轴边界
    for (int i = 0; i < n; ++i) {
      sweep.emplace_back(rectangles[i][0], i, 1);   // 左边界1
      sweep.emplace_back(rectangles[i][2], i, -1);  // 右边界-1
    }
    sort(sweep.begin(), sweep.end());
    int s = sweep.size();
    long long ans = 0;
    for (int i = 0; i < s; ++i) {
      int j = i;
      while (j + 1 < s and
             get<0>(sweep[i]) ==
                 get<0>(sweep[j + 1])) {  // X相等，即相同的Y轴边界
        ++j;
      }
      if (j + 1 == s) break;
      for (int k = i; k <= j; ++k) {  // 对i,j区间内的边界
        // C++17 Structured Binding
        // auto&& [_, idx, diff] = sweep[i];
        int idx, diff;
        tie(std::ignore, idx, diff) = sweep[k];
        int left = rectangles[idx][1], right = rectangles[idx][3];
        for (int x = 0; x < m - 1; ++x) {  // 区间高度
          if (left <= hbound[x] and  // 如果当前边界的下界小于区间
              hbound[x + 1] <= right) {  //并且上界高于区间
            seg[x] += diff;              // 区间增加或减少
          }
        }
      }
      int cover = 0;
      for (int k = 0; k < m - 1; ++k) {
        if (seg[k] > 0) {
          cover += (hbound[k + 1] - hbound[k]);
        }
      }
      ans += static_cast<long long>(cover) *
             (get<0>(sweep[j + 1]) - get<0>(sweep[j]));
      i = j;
    }
    return ans % static_cast<int>(1e9 + 7);
  }
};

int main(int argc, char const* argv[]) {
  Matrix<int> rectangles{{0, 0, 2, 2}, {1, 0, 2, 3}, {1, 1, 3, 1}};
  Solution sol;
  cout << sol.rectangleArea(rectangles) << endl;
  return 0;
}
