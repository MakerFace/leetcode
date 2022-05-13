/**
 * @file 133.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>

#include "common/GraphNode.hpp"
using namespace std;

class Solution {
 public:
  Node* cloneGraph(Node* node) { return nullptr; }
};

int main(int argc, char const* argv[]) {
  auto node = matrix2graph({{1, 3}, {0, 2}, {1, 3}, {0, 2}});
  print_graph(node);
  return 0;
}
