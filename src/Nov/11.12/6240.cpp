/**
 * @file 6240.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-12
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <functional>
#include <vector>

#include "common/Matrix.hpp"
#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int mostProfitablePath(vector<vector<int>>& edges, int bob,
                         vector<int>& amount) {
    vector<vector<int>> graph(amount.size());
    for (auto& e : edges) {
      graph[e[0]].emplace_back(e[1]);
      graph[e[1]].emplace_back(e[0]);
    }
    int idx = bob;
    path = 0;
    while (idx) {
      idx = *min_element(graph[idx].begin(), graph[idx].end());
      path++;
    }
    max_value = INT_MIN;
    dfs(graph, amount, 0, 0, 0);
    return max_value;
  }

 private:
  void dfs(vector<vector<int>>& graph, vector<int>& amount, int idx, int level,
           int value) {
    if (graph[idx].empty()) {
      max_value = max(max_value, value);
    }
    if (level < path / 2) {
      value += amount[idx];
    }
    else if (path % 2 )
    for (int i = 1; i < graph[idx].size(); ++i) {
    }
  }

 private:
  int max_value;
  int path;
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.12/6240.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto edges = string2matrix(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto bob = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto amount = string2vector(buf);
    auto ans = sol.mostProfitablePath(edges, bob, amount);
    std::cout << ans << std::endl;
  }
  return 0;
}
