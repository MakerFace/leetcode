/**
 * @file 864.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-10
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <array>
#include <cctype>
#include <functional>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <utility>

#include "common/Matrix.hpp"
#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int shortestPathAllKeys(vector<string>& grid) {
    const int m = grid.size(), n = grid[0].size();
    // int mask = 0;
    int target = 0, ans = 0;
    unordered_set<int> state;
    queue<tuple<int, int, int>> que;
    int i = 0, j = 0;
    for (auto&& g : grid) {
      j = 0;
      for (auto c : g) {
        if (islower(c)) {
          target |= Mask[c - 'a'];
        }
        if (c == '@') {
          state.insert(idx2key(i, j, 0));
          que.emplace(i, j, 0);
        }
        ++j;
      }
      ++i;
    }
    while (not que.empty()) {
      ++ans;
      const int size = que.size();
      for (int k = 0; k < size; ++k) {
        auto front = que.front();
        que.pop();
        i = get<0>(front), j = get<1>(front);
        int mask = get<2>(front);
        for (auto& d : dir) {
          int x = i + d[0], y = j + d[1];
          if (x >= 0 and x < m and y >= 0 and y < n and grid[x][y] != '#') {
            if (std::islower(grid[x][y])) {
              auto nmask = (mask | Mask[grid[x][y] - 'a']);
              if (state.count(idx2key(x, y, nmask)) == 0) {
                state.insert(idx2key(x, y, nmask));
                que.emplace(x, y, nmask);  // 标识枚举
                if (nmask == target) {
                  return ans;
                }
              }
            } else if (std::isupper(grid[x][y])) {
              if ((mask & Mask[grid[x][y] - 'A']) and  // 有钥匙可以走
                  state.count(idx2key(x, y, mask)) == 0) {  // 没有走过
                state.insert(idx2key(x, y, mask));
                que.emplace(x, y, mask);
              }
            } else {
              if (state.count(idx2key(x, y, mask)) == 0) {
                state.insert(idx2key(x, y, mask));
                que.emplace(x, y, mask);
              }
            }
          }
        }
      }
    }
    return -1;
  }

 private:
  int idx2key(int i, int j, int mask) { return ((i * 100 + j) << 6) + mask; }

 private:
  array<array<int, 2>, 4> dir = {array<int, 2>{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  const array<int, 6> Mask{1, 2, 4, 8, 16, 32};
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.10/864.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto grid = string2vector<string>(buf);
    auto ans = sol.shortestPathAllKeys(grid);
    std::cout << ans << std::endl;
  }
  return 0;
}
