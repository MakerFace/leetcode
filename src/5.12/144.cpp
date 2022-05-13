/**
 * @file 144.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
#include "common/utils.hpp"
using namespace std;
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> s;
    s.push(root);
    while (not s.empty()) {
      auto node = s.top();
      s.pop();
      if (node->right) s.push(node->right);
      if (node->left) s.push(node->left);
      result.push_back(node->val);
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  auto root = list2tree({1, 2, 3});
  Solution ans;
  auto res = ans.preorderTraversal(root);
  print_vector(res);
  return 0;
}
