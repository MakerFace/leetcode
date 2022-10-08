/**
 * @file fall-2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-07
 */

#include <bits/stdc++.h>

#include "common/TreeNode.hpp"

using namespace std;

class Solution {
 public:
  TreeNode* expandBinaryTree(TreeNode* root) {
    if (not root) return root;
    int val = -2;
    queue<TreeNode*> que;
    queue<int> sta;
    que.emplace(root);
    sta.emplace(0);  // no parent
    while (not que.empty()) {
      int n = static_cast<int>(que.size());
      for (int i = 0; i < n; ++i) {
        auto& top = que.front();
        que.pop();
        if (top->left) {
          que.emplace(top->left);
          top->left = new TreeNode(val, top->left, nullptr);
        }
        if (top->right) {
          que.emplace(top->right);
          top->right = new TreeNode(val, nullptr, top->right);
        }
      }
    }
    return root;
  }
};

int main(int argc, char const* argv[]) {
  auto root = string2tree("[7]");
  Solution sol;
  root = sol.expandBinaryTree(root);
  println_tree(root);
  delete_tree(root);
  return 0;
}
