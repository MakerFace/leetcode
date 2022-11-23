/**
 * @file 764.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-09
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <array>
#include <vector>

#include "common/Matrix.hpp"

using namespace std;

class Solution {
 public:
  int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
    const int len = mines.size();
    vector<vector<array<int, 4>>> dp(
        len + 1, vector<array<int, 4>>(len + 1, array<int, 4>{-1}));
    dp[0][0] = array<int, 4>{0};

    for (int i = 0; i < len; ++i) {
      for (int j = 0; j < len; ++j) {
        if (mines[i][j]) {
          for (int k = 0; k < 4; ++k) {
            dp[i][j][k] = dp[i + dir[k][0]][j + dir[k][1]] + 1;
          }
        }
      }
    }
    test = dir[0];
    return *min_element(dp[len - 1][len - 1].begin(),
                        dp[len - 1][len - 1].end());
  }

 private:
  array<int, 2> test{1, 2};
  array<array<int, 2>, 4> dir{array<int, 2>{0, -1}, {0, 1}, {-1, 0}, {0, 1}};
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.09/764.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto mines = string2matrix(buf);
    auto ans = sol.orderOfLargestPlusSign(n, mines);
    std::cout << ans << std::endl;
  }
  return 0;
}
