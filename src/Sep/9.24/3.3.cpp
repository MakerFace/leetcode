/**
 * @file 3.3.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-24
 */

#include <bits/stdc++.h>

#include "common/Matrix.hpp"

using namespace std;

class Solution {
 public:
  vector<vector<int>> ballGame(int num, vector<string>& plate) {
    vector<vector<int>> ans;
    int n = static_cast<int>(plate.size());
    int m = static_cast<int>(plate[0].size());
    vector<vector<int>> state(n, vector<int>(n));
    int step;
    vector<int> dir_E{2, 3, 1, 0}, dir_W{3, 2, 0, 1};
    function<void(int, int, int)> dfs = [&](int i, int j, int dir) {
      if (dir == 0)  // up
      {
        i--;
        if (i == 0 and (j != 0 and j != m - 1) and step > 0 and
            plate[i][j] == '.') {
          ans.emplace_back(vector<int>{i, j});
        }
      } else if (dir == 1)  // down
      {
        i++;
        if (i == n - 1 and (j != 0 and j != m - 1) and step > 0 and
            plate[i][j] == '.') {
          ans.emplace_back(vector<int>{i, j});
        }
      } else if (dir == 2)  // left
      {
        j--;
        if (j == 0 and (i != 0 and i != n - 1) and step > 0 and
            plate[i][j] == '.') {
          ans.emplace_back(vector<int>{i, j});
        }
      } else if (dir == 3)  // right
      {
        j++;
        if (j == m - 1 and (i != 0 and i != n - 1) and step > 0 and
            plate[i][j] == '.') {
          ans.emplace_back(vector<int>{i, j});
        }
      }
      --step;
      if (i < 0 or i >= n or j < 0 or j >= m or step <= 0)
        return;  // out of bound
      if (plate[i][j] == 'W') {
        dir = dir_W[dir];
      } else if (plate[i][j] == 'E') {
        dir = dir_E[dir];
      } else if (plate[i][j] == 'O')
        return;
      dfs(i, j, dir);
    };
    int i = 0, j;
    for (auto& s : plate) {
      j = 0;
      for (auto& c : s) {
        if (c == 'O') {
          int dir = 0;
          for (int k = 0; k < 4; ++k) {
            step = num;
            dfs(i, j, dir);
            dir++;
          }
        }
        ++j;
      }
      ++i;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  vector<string> plate{"E...W..WW", ".E...O...", "...WO...W", "..OWW.O..",
                       ".W.WO.W.E", "O..O.W...", ".OO...W..", "..EW.WEE."};
  Solution sol;
  auto ans = sol.ballGame(41, plate);
  println_matrix(ans);
  return 0;
}
