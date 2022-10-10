#ifndef GRAPHNODE_HPP
#define GRAPHNODE_HPP

#include <vector>

#include "common/Matrix.hpp"
// Definition for a Node.
namespace graph {

class Node {
 public:
  int val;
  std::vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }
  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

}  // namespace graph

graph::Node* matrix2graph(const Matrix<int>& mat) {
  using graph::Node;
  std::vector<Node*> vertex(mat.size());
  for (size_t i = 0; i < mat.size(); ++i) {
    std::vector<Node*> neighbors(mat[i].size());
    for (size_t j = 0; j < mat[i].size(); ++j) {
      int v = mat[i][j];
      if (not vertex[v]) {
        vertex[v] = new Node(v);
      }
      neighbors[j] = vertex[v];
    }
    if (not vertex[i]) {
      vertex[i] = new Node(i, neighbors);
    } else {
      vertex[i]->neighbors = neighbors;
    }
  }
  return vertex[0];
}

void print_graph(graph::Node* node) {}

template <typename T = int>
Matrix<T> string2graph(const std::string& str) {
  return string2matrix<T>(str);
}

#endif  // GRAPHNODE_HPP
