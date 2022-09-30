/**
 * @file 2.2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-24
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int transportationHub(vector<vector<int>>& path) {
    int len = static_cast<int>(path.size());
    unordered_set<int> all_node;
    unordered_map<int, int> node;
    for (int i = 0; i < len; i++) {
      all_node.insert(path[i][0]);
      all_node.insert(path[i][1]);
      node[path[i][1]]++;
      node[path[i][0]]--;
    }
    len = static_cast<int>(all_node.size()) - 1;
    for (auto& n : node) {
      if (n.second == len) return n.first;
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> path{{1, 3}, {1, 2}, {0, 2}, {3, 2}};
  Solution sol;
  std::cout << sol.transportationHub(path) << std::endl;
  return 0;
}
