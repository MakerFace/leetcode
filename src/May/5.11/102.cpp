/**
 * @file 102.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-11
 */
#include <bits/stdc++.h>

#include "common/Matrix.hpp"
#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> result;
    q.push(root);
    while (not q.empty()) {
      int size = q.size();
      vector<int> temp(size);
      for (int i = 0; i < size; ++i) {
        auto node = q.front();
        q.pop();
        if (node) {
          temp[i] = node->val;
          if (node->left) q.push(node->left);
          if (node->right) q.push(node->right);
        } else {
          return result;
        }
      }
      result.emplace_back(temp);
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  auto root = string2tree("[]");
  auto res = ans.levelOrder(root);
  print_matrix(res);
  return 0;
}
