/**
 * @file 226.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdtr1c++.h>

#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (not root) return nullptr;

    auto left = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(left);
    return root;
  }
};

int main(int argc, char const* argv[]) {
  auto root = list2tree({4, 2, 7, 1, 3, 6, 9});
  Solution ans;
  auto res = ans.invertTree(root);
  println_tree(res);
  return 0;
}
