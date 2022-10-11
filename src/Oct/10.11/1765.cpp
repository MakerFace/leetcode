/**
 * @file 1765.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-11
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = static_cast<int>(isWater.size());
    int n = static_cast<int>(isWater[0].size());
    vector<vector<int>> fill(m, vector<int>(n, -1));
    queue<pair<int, int>> que;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isWater[i][j]) {
          fill[i][j] = 0;
          que.emplace(i, j);
        }
      }
    }

    while (not que.empty()) {
      auto top = que.front();
      que.pop();
      for (auto& d : dir) {
        int i = top.first + d[0], j = top.second + d[1];
        if (i >= 0 and i < m and j >= 0 and j < n and fill[i][j] == -1) {
          fill[i][j] = fill[top.first][top.second] + 1;
          que.emplace(i, j);
        }
      }
    }
    return fill;
  }

 private:
  int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
};

int main(int argc, char const* argv[]) {
  Solution sol;
  string s = string(PROJECT_PATH).append("/src/Oct/10.11/1765.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    s = buf;
    Matrix<int> isWater = string2graph(s);
    auto ans = sol.highestPeak(isWater);
    std::cout << ans << std::endl;
  }
  return 0;
}
