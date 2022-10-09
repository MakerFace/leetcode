/**
 * @file 669.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-10
 */

#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 public:
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    while (root and not inbound(root->val, low, high)) {  // find root
      if (root->val < low) {      // find root in right tree
        delete_tree(root->left);  // TODO remove before submit
        auto tmp = root;
        root = root->right;
        delete tmp;
      } else {                     // find root in left tree
        delete_tree(root->right);  // TODO remove before submit
        auto tmp = root;
        root = root->left;
        delete tmp;
      }
    }
    if (not root) return nullptr;
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
  }

 private:
  bool inbound(int value, int low, int high) {
    return value >= low and value <= high;
  }
};

int main(int argc, char const* argv[]) {
  auto root = string2tree("[3,0,4,null,2,null,null,1]");
  Solution sol;
  auto res = sol.trimBST(root, 1, 3);
  std::cout << res << std::endl;
  delete_tree(root);
  return 0;
}
