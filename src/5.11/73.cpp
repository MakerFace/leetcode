/**
 * @file 73.cpp
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
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> vec(n, 1);
    for (int i = 0; i < m; ++i) {
      bool zero = false;
      for (int j = 0; j < n; ++j) {
        if (vec[j]) {  // vec不等于0就赋值，等于0就再也不赋值
          vec[j] = matrix[i][j];
        }
        if (not matrix[i][j]) {
          zero = true;
          for (int k = i; k >= 0; --k) {
              matrix[k][j] = 0;
          }
        }
        matrix[i][j] = vec[j];
      }
      if (zero) {
        for (int j = 0; j < n; ++j) matrix[i][j] = 0;
      }
    }
  }
};

int main(int argc, char const* argv[]) {
  Matrix<int> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}, {0, 1, 2, 3}};
  Solution ans;
  ans.setZeroes(matrix);
  print_matrix(matrix);
  return 0;
}
