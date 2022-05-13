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
    // stack<pair<TreeNode*, int>> s;
    list<pair<TreeNode*, int>> temp;
    int sum = 0;
    temp.push_back(make_pair(root, 0));
    sum += root->val;
    while (not temp.empty()) {
      auto& top = temp.back();
      if (top.second == 0) {
        if (top.first->left) {
          temp.push_back(make_pair(top.first->left, 0));
          sum += top.first->left->val;
        }
        top.second++;
      } else if (top.second == 1) {
        if (top.first->right) {
          temp.push_back(make_pair(top.first->right, 0));
          sum += top.first->right->val;
        }
        top.second++;
      } else {
        if (not top.first->left and not top.first->right and sum == targetSum) {
          vector<int> tmp(temp.size());
          auto ptr = temp.begin();
          for (size_t i = 0; i < temp.size(); i++) {
            tmp[i] = (ptr++)->first->val;
          }
          result.push_back(tmp);
        }
        // 不能交换下面两句话，使用后再pop，否则会被析构掉！
        sum -= top.first->val;
        temp.pop_back();
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
