/**
 * @file 934.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-25
 */
#include "common/GraphNode.hpp"
#include "common/Matrix.hpp"
#include <fstream>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {

public:
  int shortestBridge(vector<vector<int>> &grid) {
    int n = static_cast<int>(grid.size());
    function<void(int, int)> dfs;
    queue<pair<int, int>> que;
    dfs = [&](int i, int j) {
      grid[i][j] = 2;
      que.emplace(i, j);
      for (auto &d : dir) {
        int x = i + d[0], y = j + d[1];
        if (x >= 0 and x < n and y >= 0 and y < n and grid[x][y] == 1) {
          dfs(x, y);
        }
      }
    };
    
    for (int i = 0; i < n; ++i) {
      bool work = false;
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          dfs(i, j);
          work = true;
          break;
        }
      }
      if (work)
        break;
    }
    int ans = 0;
    while (not que.empty()) {
      int len = que.size();
      for (int k = 0; k < len; ++k) {
        auto top = que.front();
        for (auto &d : dir) {
          int x = top.first + d[0], y = top.second + d[1];
          if (x >= 0 and x < n and y >= 0 and y < n) {
            if (grid[x][y] == 0) {
              grid[x][y] = 3;
              que.emplace(x, y);
            } else if (grid[x][y] == 1) {
              return ans;
            }
          }
        }
        que.pop();
      }
      ++ans;
    }
    return ans;
  }

private:
  int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.25/934.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto grid = string2graph(buf);
    auto ans = sol.shortestBridge(grid);
    std::cout << ans << std::endl;
  }
  return 0;
}
