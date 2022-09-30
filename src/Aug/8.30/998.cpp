/**
 * @file 998.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-08-30
 */

#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 public:
  TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (root == nullptr) {
      root = new TreeNode(val);
      return root;
    }
    if (root->val < val) { // 新节点成为根
      auto new_root = new TreeNode(val);
      new_root->left = root;
      root = new_root;
      return new_root;
    }

    root->right = insertIntoMaxTree(root->right, val);
    return root;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  auto root = list2tree({5,2,4,null,1});
  int val = 3;
  TreeNode* root_node = sol.insertIntoMaxTree(root, val);
  print_tree(root_node);
  return 0;
}
