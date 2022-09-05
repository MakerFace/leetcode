/**
 * @file 1582.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-05
 */

#include <bits/stdc++.h>

#include "common/Matrix.hpp"
using namespace std;

class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    int ans = 0;
    size_t r = mat.size();
    size_t c = mat[0].size();
    vector<int> index(c, 0);
    for (size_t i = 0; i < r; i++) {
      int count = 0;
      for (size_t j = 0; j < c; j++) {
        if (mat[i][j] == 1) {
          ++count;
          if (index[j] == 0) {
            index[j] = 1;
          } else {
            index[j] = 2;
          }
        }
      }
      if (count > 1) {
        for (size_t j = 0; j < c; j++) {
          if (mat[i][j] == 1) {
            index[j] = 2;
          }
        }
      }
    }
    for (size_t j = 0; j < c; j++) {
      if (index[j] == 1) {
        ++ans;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  Matrix<int> mat(
      {{0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 1, 1}});
  cout << sol.numSpecial(mat) << endl;
  return 0;
}
