/**
 * @file 74.cpp
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
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    // 纵向二分查找
    int i = 0, j = m - 1;
    while (i <= j) {
      int mid = (i + j) / 2;
      if (matrix[mid][0] == target)
        return true;
      else if (matrix[mid][0] < target) {
        if ((mid == j) or                     // mid已经是最后一行
            (matrix[mid + 1][0] > target)) {  // 或者下一行大于target
          i = mid;
          break;
        } else {
          i = mid + 1;
        }
      } else {                                // matrix[mid][0] > target
        if ((mid == i) or                     // mid是第一行
            (matrix[mid - 1][0] < target)) {  // 或者上一行小于target
          i = max(mid - 1, 0);
          break;
        } else {
          j = mid - 1;
        }
      }
    }
    // 横向二分查找
    int k = 0;
    j = n - 1;
    while (k <= j) {
      int mid = (k + j) / 2;
      if (matrix[i][mid] == target) {
        return true;
      } else if (matrix[i][mid] < target) {
        k = mid + 1;
      } else {
        j = mid - 1;
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  Matrix<int> matrix{{1}};
  int target;
  while (cin >> target) {
    std::cout << boolalpha << ans.searchMatrix(matrix, target) << std::endl;
  }
  return 0;
}
