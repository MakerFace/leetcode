/**
 * @file 785.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-10
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
  enum class Color { UNCOLORED, RED, GREEN };

 public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n = static_cast<int>(graph.size());
    color.resize(n);
    valid = true;
    for (int i = 0; i < n; ++i) {
      if (color[i] == Color::UNCOLORED) bfs(graph, Color::RED, i);
      if (not valid) break;
    }
    return valid;
  }

 private:
  void bfs(vector<vector<int>>& graph, Color c, int node) {
    queue<int> que;
    que.push(node);
    color[node] = c;
    int top;
    while (not que.empty()) {
      top = que.front();
      que.pop();
      c = color[top] == Color::RED ? Color::GREEN : Color::RED;
      for (auto nei : graph[top]) {
        if (color[nei] == Color::UNCOLORED) {
          color[nei] = c;
          que.push(nei);
        } else if (color[nei] != c) {
          valid = false;
          return;
        }
      }
    }
  }

  /**
   * @brief 相邻节点染色法，如果重复节点染色不一致，就非法，一致跳过
   */
  void dfs(vector<vector<int>>& graph, Color c, int node) {
    color[node] = c;
    c = c == Color::RED ? Color::GREEN : Color::RED;
    for (auto neighbor : graph[node]) {
      if (color[neighbor] == Color::UNCOLORED) {
        dfs(graph, c, neighbor);
        if (not valid) return;
      } else if (color[neighbor] != c) {
        valid = false;
        return;
      }
    }
  }

 private:
  vector<Color> color;
  bool valid;
};

constexpr int len() { return 5; }

int main(int argc, char const* argv[]) {
  Solution sol;
  string s = string(PROJECT_PATH).append("/src/Oct/10.10/785.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    s = buf;
    auto graph = string2graph(s);
    auto ans = sol.isBipartite(graph);
    std::cout << boolalpha << ans << std::endl;
  }
  return 0;
}
