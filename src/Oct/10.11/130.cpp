/**
 * @file 130.cpp
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
  /**
   * @brief bfs, dfs思路一样，把外围染成A色就行
   * 第二次遍历把O变为X，A变为O
   */
  void solve(vector<vector<char>>& board) {
    int m = static_cast<int>(board.size());
    int n = static_cast<int>(board[0].size());
    unordered_map<int, bool> map;
    function<bool(int, int)> inbound = [m, n](int i, int j) {
      return i >= 0 and i < m and j >= 0 and j < n;
    };
    // function<void(int, int)> dfs;
    // dfs = [&](int i, int j) -> void {
    //   board[i][j] = 'A';
    //   for (auto& d : dir) {
    //     int x = i + d[0], y = j + d[1];
    //     if (inbound(x, y) and board[x][y] == 'O') {
    //       board[x][y] = 'A';
    //       dfs(x, y);
    //     }
    //   }
    // };
    // for (int i = 0; i < m; ++i) {
    //   if (i == 0 or i == m - 1) {
    //     for (int j = 0; j < n; ++j) {
    //       if (board[i][j] == 'O') dfs(i, j);
    //     }
    //   } else {
    //     if (board[i][0] == 'O') dfs(i, 0);
    //     if (board[i][n - 1] == 'O') dfs(i, n - 1);
    //   }
    // }
    function<void(int, int)> bfs = [&](int i, int j) {
      queue<pair<int, int>> que;
      que.emplace(i, j);
      board[i][j] = 'A';
      while (not que.empty()) {
        auto top = que.front();
        que.pop();
        for (auto& d : dir) {
          int x = top.first + d[0], y = top.second + d[1];
          if (inbound(x, y) and board[x][y] == 'O') {
            board[x][y] = 'A';
            que.emplace(x, y);
          }
        }
      }
    };

    for (int i = 0; i < m; ++i) {
      if (i == 0 or i == m - 1) {
        for (int j = 0; j < n; ++j) {
          if (board[i][j] == 'O') bfs(i, j);
        }
      } else {
        if (board[i][0] == 'O') bfs(i, 0);
        if (board[i][n - 1] == 'O') bfs(i, n - 1);
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        board[i][j] = board[i][j] == 'O' ? 'X' : board[i][j] == 'A' ? 'O' : 'X';
      }
    }
  }

 private:
  int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
  int pair2key(int i, int j) { return i * 1000 + j; }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  string s = string(PROJECT_PATH).append("/src/Oct/10.11/130.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    s = buf;
    auto board = string2matrix<char>(s);
    sol.solve(board);
    std::cout << board << std::endl;
  }
  return 0;
}
