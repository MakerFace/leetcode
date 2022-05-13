/**
 * @file 113.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-13
 */
#include <bits/stdc++.h>

#include "common/Matrix.hpp"
#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    if (not root) return result;
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
          vector<int> temp;
          stack<pair<TreeNode*, int>> s_r;
          while (not s.empty()) {
            s_r.push(s.top());
            s.pop();
          }
          while (not s_r.empty()) {
            s.push(s_r.top());
            temp.emplace_back(s_r.top().first->val);
            s_r.pop();
          }
          result.push_back(temp);
        }
        s.pop();
        sum -= top.first->val;
      }
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  auto root = string2tree("[5,4,8,11,null,13,4,7,2,null,null,5,1]");
  int targetSum;
  while (cin >> targetSum) {
    auto res = ans.pathSum(root, targetSum);
    println_matrix(res);
  }
  return 0;
}
