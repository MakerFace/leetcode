/**
 * @file 04.06.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-16
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (not root) return nullptr;
    TreeNode* node = root;
    stack<TreeNode*> s;
    while (node) {
      if (node->val == p->val) break;
      s.push(node);
      if (node->val < p->val)
        node = node->right;
      else {
        node = node->left;
      }
    }
    if (not node) return nullptr;
    if (node->right) {
      node = node->right;
      while (node->left) {
        node = node->left;
      }
      return node;
    } else {
      while (not s.empty()) {
        auto top = s.top();
        if (top->val > p->val) {
          return top;
        }
        s.pop();
      }
      return nullptr;
    }
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  int n;
  //   auto root = string2tree("[8,4,12,2,6,10,14,1,3,5,7,9,11,13,15]");
  auto root = string2tree("[5,3,6,2,4,null,null,1]");
  while (cin >> n) {
    auto node = new TreeNode(n);
    auto res = ans.inorderSuccessor(root, node);
    if (res)
      std::cout << res->val << std::endl;
    else
      std::cout << "nullptr" << std::endl;
  }
  return 0;
}
