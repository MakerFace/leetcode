/**
 * @file ms01.08.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-30
 */
#include <bits/stdc++.h>

#include "common/Matrix.hpp"

using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    // vector<tuple<int, int>> zeros;
    unordered_set<int> col_zeros, row_zeros;
    int n = static_cast<int>(matrix.size());
    if (not n) return;
    int m = static_cast<int>(matrix[0].size());
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (not matrix[i][j]) {
          col_zeros.insert(j);
          row_zeros.insert(i);
        }
      }
    }
    for (auto& row : row_zeros) {
      for (int j = 0; j < m; ++j) {
        matrix[row][j] = 0;
      }
    }
    for (auto& col : col_zeros) {
      for (int i = 0; i < n; ++i) {
        matrix[i][col] = 0;
      }
    }
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  Matrix<int> matrix{{0, 1, 2, 0}};
  sol.setZeroes(matrix);
  println_matrix(matrix);
  return 0;
}
