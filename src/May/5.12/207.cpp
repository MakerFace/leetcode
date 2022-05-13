/**
 * @file 207.cpp
 * @brief top sort
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // 邻接表存图，下标为节点编号，对应vector为指向的其他节点
    vector<int> graph[numCourses];
    unordered_map<int, int> degrees;
    for (size_t i = 0; i < prerequisites.size(); i++) {
      graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
      degrees[prerequisites[i][0]]++;
      auto iter = degrees.find(prerequisites[i][1]);
      if (iter == degrees.end()) {
        degrees[prerequisites[i][1]] = 0;
      }
    }
    // 统计入度
    int count = 0;
    int i;
    while (count < numCourses) {
      i = -1;
      for (auto& d : degrees) {
        if (d.second == 0) {
          i = d.first;
          degrees.erase(d.first);
          ++count;
          break;
        }
      }
      if (i < 0) break;
      for (auto g : graph[i]) {
        --degrees[g];  // 更新其他节点的入度
      }
    }
    return degrees.empty();
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  int numCourses = 6;
  vector<vector<int>> prerequisites{{2, 1}, {3, 1}, {5, 2},
                                    {4, 2}, {4, 3}, {5, 4}};
  std::cout << boolalpha << ans.canFinish(numCourses, prerequisites)
            << std::endl;
  return 0;
}
