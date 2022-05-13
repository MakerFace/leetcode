/**
 * @file 117.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-13
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

struct Node {
  int val;
  Node *left, *right;
  Node *next;
  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int x, Node *left, Node *right)
      : val(x), left(left), right(right), next(nullptr) {}
};

class Solution {
 public:
  Node *connect(Node *root) {
    queue<Node *> q;
    q.push(root);
    while (not q.empty()) {
      auto size = q.size();
      for (size_t i = 0; i < size; ++i) {
        auto node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        if (i < size - 1) node->next = q.front();
      }
    }
    return root;
  }
};

template <>
void println_tree(Node *root) {
  std::cout << "[";
  auto r = root;
  while (r) {
    auto node = r;
    while (node) {
      std::cout << node->val << ",";
      node = node->next;
    }
    std::cout << "#,";
    r = r->left;
  }
  if (root) std::cout << "\b";
  std::cout << "]" << std::endl;
}

int main(int argc, char const *argv[]) {
  auto root = string2tree<Node>("[1,2,3,4,5,null,7]");
  Solution ans;
  auto res = ans.connect(root);
  println_tree(res);
  return 0;
}
