/**
 * @file 827.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-18
 */

#include <bits/stdc++.h>

#include "common/Matrix.hpp"

using namespace std;

class Solution {
 public:
  int largestIsland(vector<vector<int>>& grid) {
    int n = static_cast<int>(grid.size());
    vector<int> zeros;
    len = n * n;
    disjoint.resize(n * n);
    rank.resize(n * n);
    int idx;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        idx = i * n + j;
        if (not grid[i][j]) {
          disjoint[idx] = idx;
          rank[idx] = 0;
          zeros.emplace_back(idx);
          continue;
        }
        rank[idx] = 1;
        disjoint[idx] = idx;
        if (j > 0 and grid[i][j - 1]) {  // 左边是1，合并当前集合和左集合
          // disjoint[idx] = disjoint[idx - 1];  //当前集合的父等于左集合父
          // rank[disjoint[idx - 1]]++;          // 左边集合数量+1
          union_set(idx - 1, idx);
        }
        if (i > 0 and grid[i - 1][j]) {  // 上边是1，合并左集合和上集合
          union_set(idx, idx - n);
        }
      }
    }
    if (zeros.empty()) return n * n;

    int ans = 0;
    for (auto& zero : zeros) {
      int up = -1, down = -1, left = -1, right = -1;
      int i = zero / n;
      int j = zero % n;
      if (j - 1 >= 0) {  // 左边是1合并
        left = find_set(zero - 1);
      }
      if (i - 1 >= 0) {  // 上边是1合并
        up = find_set(zero - n);
      }
      if (j + 1 < n) {  // 右边是1合并
        right = find_set(zero + 1);
      }
      if (i + 1 < n) {  // 下边是1合并
        down = find_set(zero + n);
      }
      int area = 0;
      if (left != up and left != right and left != down and left != -1)
        area += rank[left];
      if (up != right and up != down and up != -1) area += rank[up];
      if (right != down and right != -1) area += rank[right];
      if (down != -1) area += rank[down];
      ans = max(ans, area);
    }

    return ans + 1;
  }

 private:
  /// 初始化并查集
  // void make_set(vector<vector<int>>& grid) {
  //   for (size_t i = 0; i < len; i++) {
  //     disjoint[i] = i;
  //     rank[i] = 1;
  //   }
  // }

  /// 带路径压缩的查找
  int find_set(int x) {
    if (disjoint[x] != x) {
      disjoint[x] = find_set(disjoint[x]);
    }
    return disjoint[x];
  }

  /// 合并
  void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return;
    }
    if (rank[x] > rank[y]) {
      rank[x] += rank[y];
      disjoint[y] = x;
    } else {
      rank[y] += rank[x];
      disjoint[x] = y;
    }
  }

 private:
  vector<int> disjoint;
  vector<int> rank;
  int len;
};

int main(int argc, char const* argv[]) {
  Solution sol;
  Matrix<int> grid{{1, 0, 1, 0, 1},
                   {0, 1, 1, 0, 1},
                   {1, 1, 1, 0, 0},
                   {1, 0, 1, 1, 1},
                   {0, 0, 1, 1, 0}};
  std::cout << sol.largestIsland(grid) << std::endl;
  return 0;
}
