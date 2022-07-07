/**
 * @file 235.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-22
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
      if (p->val > root->val and q->val > root->val) {
        root = root->right;
      } else if (p->val < root->val and q->val < root->val) {
        root = root->left;
      } else {
        return root;
      }
    }
    return nullptr;
  }
};

int main(int argc, char const* argv[]) {
  auto root = string2tree("[6,2,8,0,4,7,9,null,null,3,5]");
  auto p = new TreeNode(2);
  auto q = new TreeNode(8);
  Solution ans;
  std::cout << ans.lowestCommonAncestor(root, p, q)->val << std::endl;
  return 0;
}
