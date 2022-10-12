/**
 * @file 419.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-12
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    m = static_cast<int>(board.size());
    n = static_cast<int>(board[0].size());
    // used.resize(m, vector<int>(n));
    // for (int i = 0; i < m; ++i) {
    //   for (int j = 0; j < n; ++j) {
    //     if (board[i][j] == 'X' and not used[i][j]) ++ans, dfs(board, i, j);
    //   }
    // }

    //////////////////////////一趟扫描///////////////////////
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'X') {
          if (i > 0 and board[i - 1][j] == 'X') continue;
          if (j > 0 and board[i][j - 1] == 'X') continue;
          ans++;
        }
      }
    }

    return ans;
  }

  //  private:
  // void dfs(vector<vector<char>>& board, int i, int j) {
  //   used[i][j] = 1;
  //   for (auto& d : dir) {
  //     int x = i + d[0], y = j + d[1];
  //     if (x >= 0 and x < m and y >= 0 and y < n and board[x][y] == 'X' and
  //         not used[x][y])
  //       dfs(board, x, y);
  //   }
  // }

 private:
  // int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
  int ans = 0;
  int m, n;
  // vector<vector<int>> used;
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.12/419.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto board = string2matrix<char>(s);
    auto ans = sol.countBattleships(board);
    std::cout << ans << std::endl;
  }
  return 0;
}
