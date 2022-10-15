#ifndef GRAPHNODE_HPP
#define GRAPHNODE_HPP

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

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

void print_graph(const graph::Node* node, std::ostream& out = std::cout) {
  if (node) {
    std::map<int, std::vector<int>> nei_map;
    std::queue<const graph::Node*> que;
    nei_map[1];
    que.emplace(node);
    while (not que.empty()) {
      auto top = que.front();
      que.pop();
      for (auto& nei : top->neighbors) {
        if (nei_map.count(nei->val) == 0) {
          que.emplace(nei);
          nei_map[nei->val];
        }
        nei_map[top->val].emplace_back(nei->val);
      }
    }
    out << "[";
    for (auto& neighbor : nei_map) {
      out << "[";
      for (auto node : neighbor.second) {
        out << node << ",";
      }
      if (not neighbor.second.empty()) out << "\b";
      out << "]";
    }
    out << "]";
  } else {
    out << "[]";
  }
}

std::ostream& operator<<(std::ostream& out, const graph::Node& node) {
  print_graph(&node, out);
  return out;
}

void delete_graph(graph::Node* node) {
  if (node) {
    std::unordered_set<int> set;
    std::queue<graph::Node*> que;
    std::vector<graph::Node*> nodes;
    que.emplace(node);
    set.insert(node->val);
    while (not que.empty()) {
      auto top = que.front();
      que.pop();
      for (auto& nei : top->neighbors) {
        if (set.count(nei->val) == 0) {
          que.emplace(nei);
          set.insert(nei->val);
        }
      }
      nodes.push_back(top);
    }
    for (auto& d : nodes) {
      delete d;
    }
  }
}

template <typename T = int>
Matrix<T> string2graph(const std::string& str) {
  return string2matrix<T>(str);
}

graph::Node* string2graph_node(const std::string& str) {
  graph::Node* node = nullptr;
  int n = std::count(str.begin() + 1, str.end(), '[');
  if (n > 0) {
    std::unordered_map<int, graph::Node*> map;
    for (int i = 1; i <= n; i++) {
      map[i] = new graph::Node(i);
    }
    node = map[1];
    std::vector<graph::Node*> temp;
    int i = 1;
    for (auto iter = str.cbegin(); iter != str.cend(); iter++) {
      if (not std::isdigit(*iter)) continue;
      int num = 0;
      while (std::isdigit(*iter)) {
        num *= 10;
        num += *iter - '0';
        ++iter;
      }
      temp.push_back(map[num]);
      if (*iter == ']') {
        map[i++]->neighbors.swap(temp);
      }
    }
  }
  return node;
}

#endif  // GRAPHNODE_HPP
