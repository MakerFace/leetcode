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
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n = static_cast<int>(graph.size());
    vector<set<int>> graph_set(n);
    sets[0].clear();
    sets[1].clear();
    used.clear();
    used.resize(n);
    for (int i = 0; i < n; ++i) {
      for (auto& n : graph[i]) {
        graph_set[i].insert(n);
      }
    }

    bool ans = false;
    for (int i = 0; i < n; ++i) {
      if (not used[i] and dfs(graph_set, 0, i)) ans = true;
      ans &= used[i];
    }
    return ans;
  }

 private:
  bool dfs(vector<set<int>>& graph, int sidx, int node) {
    used[node] = 1;
    for (auto n : sets[sidx]) {
      if (graph[n].find(node) != graph[n].end()) return false;
    }
    sets[sidx].insert(node);
    for (auto& n : graph[node]) {
      if (not used[n] and dfs(graph, not sidx, n)) return true;
    }

    return sets[0].size() + sets[1].size() == graph.size();
  }

 private:
  set<int> sets[2];
  vector<int> used;
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
