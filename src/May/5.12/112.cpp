/**
 * @file 112.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (not root) return false;
    stack<pair<TreeNode*, int>> s;
    int sum = 0;
    s.push(make_pair(root, 0));
    sum += root->val;
    while (not s.empty()) {
      auto& top = s.top();
      if (top.second == 0) {
        if (top.first->left) {
          s.push(make_pair(top.first->left, 0));
          sum += top.first->left->val;
        }
        top.second++;
      } else if (top.second == 1) {
        if (top.first->right) {
          s.push(make_pair(top.first->right, 0));
          sum += top.first->right->val;
        }
        top.second++;
      } else {
        if (not top.first->left and not top.first->right and sum == targetSum) {
          return true;
        }
        s.pop();
        sum -= top.first->val;
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  int target;
  auto root = string2tree("[5,4,8,11,null,13,4,7,2,null,null,null,1]");
  while (cin >> target) {
    std::cout << boolalpha << ans.hasPathSum(root, target) << std::endl;
  }
  return 0;
}
