/**
 * @file 797.cpp
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
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ans;
    int n = static_cast<int>(graph.size());
    //     vector<int> used(n);
    //     vector<int> temp(1);
    //     function<void(int)> dfs;
    //     dfs = [&](int idx) {
    //       if (idx == n - 1) {
    //         ans.emplace_back(temp);
    //         return;
    //       }
    //       for (auto& nidx : graph[idx]) {
    //         temp.push_back(nidx);
    //         dfs(nidx);
    //         temp.pop_back();
    //       }
    //     };
    //     dfs(0);
    /**************bfs****************/
    function<void()> bfs;
    bfs = [&]() {
      queue<vector<int>> que;
      que.push(vector<int>{0});
      while (not que.empty()) {
        auto temp = que.front();
        que.pop();
        for (auto& nidx : graph[temp.back()]) {
          temp.push_back(nidx);
          if (nidx == n - 1) {
            ans.emplace_back(temp);
          } else {
            que.emplace(temp);
          }
          temp.pop_back();
        }
      }
    };
    bfs();
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  string s = string(PROJECT_PATH).append("/src/Oct/10.10/797.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    s = buf;
    auto graph = string2graph(s);
    auto ans = sol.allPathsSourceTarget(graph);
    std::cout << ans << std::endl;
  }
  return 0;
}
