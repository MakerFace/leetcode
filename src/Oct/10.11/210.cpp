/**
 * @file 210.cpp
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
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    graph.resize(numCourses);
    visited.resize(numCourses);
    result.reserve(numCourses);
    // for (auto& pre : prerequisites) {
    // graph[pre[1]].emplace_back(pre[0]);
    // }
    // valid = true;
    // for (int i = 0; i < numCourses; ++i) {
    //   if (visited[i] == 0 and valid) dfs(i);
    // }
    // if (not valid) result.clear();
    // reverse(result.begin(), result.end());
    bfs(numCourses, prerequisites);
    return result;
  }

 private:
  void bfs(int numCourses, vector<vector<int>>& prerequisites) {
    queue<int> que;
    vector<int> degree(numCourses);
    for (auto& pre : prerequisites) {
      graph[pre[1]].emplace_back(pre[0]);
      degree[pre[0]]++;
    }
    for (int i = 0; i < numCourses; ++i) {
      if (not degree[i]) que.push(i);
    }
    while (not que.empty()) {
      auto top = que.front();
      que.pop();
      for (auto& g : graph[top]) {
        degree[g]--;
        if (degree[g] == 0) que.push(g);
      }
      result.push_back(top);
    }
    if (numCourses != static_cast<int>(result.size())) result.clear();
  }

  void dfs(int i) {
    if (visited[i] == 0)
      visited[i] = 1;  // studying
    else
      return;
    for (auto n : graph[i]) {
      if (visited[n] == 0 and valid)
        dfs(n);
      else if (visited[n] == 1)
        valid = false;
    }
    if (visited[i] == 1) result.push_back(i);
    visited[i] = 2;  // studied
  }

 private:
  vector<vector<int>> graph;
  vector<int> result;
  vector<int> visited;
  bool valid;
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.11/210.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto numCourses = atoi(s.c_str());
    in.getline(buf, MAX_LINE_SIZE);
    s = buf;
    auto prerequisites = string2matrix(s);
    auto ans = sol.findOrder(numCourses, prerequisites);
    std::cout << ans << std::endl;
  }
  return 0;
}
