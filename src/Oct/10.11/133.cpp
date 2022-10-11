/**
 * @file 133.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-11
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using graph::Node;
using namespace std;

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (not node) return nullptr;
    unordered_map<int, Node*> map;
    // map[1] = new Node(node->val);
    // function<void(Node*, int)> dfs;
    // dfs = [&](Node* node, int prev) {
    //   for (auto& n : node->neighbors) {
    //     if (map.count(n->val) == 0) {
    //       map[n->val] = new Node(n->val);
    //       dfs(n, n->val);
    //     }
    //     map[prev]->neighbors.emplace_back(map[n->val]);
    //   }
    // };
    // dfs(node, 1);
    function<void()> bfs = [&]() {
      queue<Node*> que;
      que.emplace(node);
      while (not que.empty()) {
        auto top = que.front();
        que.pop();
        if (map.count(top->val) == 0) map[top->val] = new Node(top->val);
        for (auto& nei : top->neighbors) {
          if (map.count(nei->val) == 0) {
            map[nei->val] = new Node(nei->val);
            que.emplace(nei);
          }
          map[top->val]->neighbors.emplace_back(map[nei->val]);
        }
      }
    };
    bfs();
    return map[1];
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  string s = string(PROJECT_PATH).append("/src/Oct/10.11/133.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    s = buf;
    auto node = string2graph_node(s);
    auto ans = sol.cloneGraph(node);
    std::cout << *ans << std::endl;
    delete_graph(node);
    delete_graph(ans);
  }
  return 0;
}
