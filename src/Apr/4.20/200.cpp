/**
 * @file 200.cpp
 * @brief 岛屿数量
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-20
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief 深度优先遍历
   * @return int
   */
  int numIslands(vector<vector<char>> &grid) {
    int res = 0;
    for (size_t i = 0; i < grid.size(); ++i) {
      for (size_t j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == '1') {
          ++res;
          remove(grid, i, j);
        }
      }
    }
    return res;
  }

 private:
  void remove(vector<vector<char>> &grid, size_t i, size_t j) {
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size()) {
      if (grid[i][j] == '0') return;
      grid[i][j] = '0';
    } else
      return;
    if (i + 1 < grid.size() && grid[i + 1][j] == '1') {
      remove(grid, i + 1, j);
    }
    if (i > 0 && grid[i - 1][j] == '1') {
      remove(grid, i - 1, j);
    }
    if (j + 1 < grid[i].size() && grid[i][j + 1] == '1') {
      remove(grid, i, j + 1);
    }
    if (j > 0 && grid[i][j - 1] == '1') {
      remove(grid, i, j - 1);
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  // vector<vector<char>> grid = {
  //     {'1', '1', '1', '1', '0'},
  //     {'1', '1', '0', '1', '0'},
  //     {'1', '1', '0', '0', '0'},
  //     {'0', '0', '0', '0', '0'}};
  // vector<vector<char>> grid = {
  //     {'1', '1', '0', '0', '0'},
  //     {'1', '1', '0', '0', '0'},
  //     {'0', '0', '1', '0', '0'},
  //     {'0', '0', '0', '1', '1'}};
  vector<vector<char>> grid = {{'1'}, {'1'}};
  std::cout << s.numIslands(grid) << std::endl;
  return 0;
}
