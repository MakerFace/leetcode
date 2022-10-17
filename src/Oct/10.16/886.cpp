/**
 * @file 886.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-16
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
  enum class Color { UNCOLORED, RED, GREEN };

 public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    graph.resize(n);
    // create graph
    for (auto& dis : dislikes) {
      graph[dis[0] - 1].emplace_back(dis[1] - 1);
      graph[dis[1] - 1].emplace_back(dis[0] - 1);
    }
    colors.resize(n, Color::UNCOLORED);
    for (int i = 0; i < n; ++i) {
      if (colors[i] == Color::UNCOLORED) {
        if (not dfs(i, Color::RED)) return false;
      }
    }
    return true;
  }

 private:
  bool dfs(int i, Color color) {
    colors[i] = color;
    color = color == Color::RED ? Color::GREEN : Color::RED;
    for (auto next : graph[i]) {
      if (colors[next] == Color::UNCOLORED) {
        dfs(next, color);
      } else if (colors[next] != color) {
        return false;
      }
    }
    return true;
  }

 private:
  vector<Color> colors;
  vector<vector<int>> graph;
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.16/886.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    s = buf;
    auto dislikes = string2matrix(s);
    auto ans = sol.possibleBipartition(n, dislikes);
    std::cout << boolalpha << ans << std::endl;
  }
  return 0;
}
