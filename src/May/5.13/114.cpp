/**
 * @file 114.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-13
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

/**
 * @brief 递归虽然优美，但是栈空间有限
 * 此外，尾递归可以写成以下循环，栈也不用
 */
class Solution {
 public:
  void flatten(TreeNode* root) {
    if (not root) return;
    auto node = root;
    while (node) {
      if (node->left) {  // 如果一棵树有左子树那么先将右子树移动到左子树的最右节点，然后将左子树变为右子树
        auto right = node->left;
        while (right->right) {
          right = right->right;
        }
        right->right = node->right;
        node->right = node->left;
        node->left = nullptr;
      }
      node = node->right;
    }
  }
};

int main(int argc, char const* argv[]) {
  auto root = string2tree("[1,2,null,5,null,3,null,4,null,6]");
  Solution ans;
  ans.flatten(root);
  println_tree(root);
  return 0;
}
