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
    for (auto& pre : prerequisites) {
      graph[pre[0]].emplace_back(pre[1]);
    }
    for (int i = 0; i < numCourses; ++i)
    {
      /* code */
    }
    
  }

 private:
  vector<vector<int>> graph;
  vector<int> result;
  vector<int> visited;
  bool valid;
};

int main(int argc, char const* argv[]) {
  Solution sol;
  string s = string(PROJECT_PATH).append("/src/Oct/10.11/210.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
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
