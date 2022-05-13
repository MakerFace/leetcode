/**
 * @file 864.cpp
 * @brief 获取所有钥匙的最短路径
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int shortestPathAllKeys(vector<string> &grid) {
    size_t i, j;
    // find start point
    for (i = 0; i < grid.size(); ++i) {
      for (j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == '@') {
          break;
        }
      }
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  vector<string> grid = {"@.a.#", "###.#", "b.A.B"};
  std::cout << ans.shortestPathAllKeys(grid) << std::endl;
  return 0;
}
