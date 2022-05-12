/**
 * @file 107.cpp
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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
    reverse(result.begin(), result.end());
    return result;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  auto root = string2tree("[3,9,20,null,null,15,7]");
  auto res = ans.levelOrderBottom(root);
  print_matrix(res);
  return 0;
}
