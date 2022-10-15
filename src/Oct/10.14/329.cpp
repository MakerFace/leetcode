/**
 * @file 329.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-14
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    maxValue = 0;
    m = static_cast<int>(matrix.size());
    n = static_cast<int>(matrix[0].size());
    memory.resize(m, vector<int>(n, -1));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dfs(matrix, i, j);
      }
    }
    return maxValue;
  }

 private:
  int dfs(vector<vector<int>>& matrix, int i, int j) {
    // auto key = idx2str(i, j);
    // auto res = map.find(key);
    // if (res != map.end()) return res->second;
    if (memory[i][j] != -1) return memory[i][j];
    int count = 1;
    for (auto& d : dir) {
      int x = i + d[0], y = j + d[1];
      if (x >= 0 and x < m and y >= 0 and y < n and
          matrix[i][j] < matrix[x][y]) {
        count = max(dfs(matrix, x, y) + 1, count);
      }
    }
    // map[key] = count;
    memory[i][j] = count;
    maxValue = max(maxValue, count);
    return count;
  }

  //   string idx2str(int i, int j) { return to_string(i * 1000 + j); }

 private:
  //   unordered_map<string, int> map;
  vector<vector<int>> memory;
  int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
  int maxValue;
  int m, n;
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.14/329.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto matrix = string2matrix(s);
    auto ans = sol.longestIncreasingPath(matrix);
    std::cout << ans << std::endl;
  }
  return 0;
}
