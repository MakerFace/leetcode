/**
 * @file 687.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-02
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 public:
  int longestUnivaluePath(TreeNode* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
  }

 private:
  int dfs(TreeNode* root, int& ans) {
    if (root == NULL) {
      return 0;
    }
    int left = dfs(root->left, ans);
    if (root->left and root->left->val == root->val) {
      ++left;
    } else {
      left = 0;
    }
    int right = dfs(root->right, ans);
    if (root->right and root->right->val == root->val) {
      ++right;
    } else {
      right = 0;
    }

    if (root->left and root->right) {
      if (root->val == root->left->val and root->val == root->right->val) {
        ans = max(ans, left + right);
      }
    }
    if (root->left and root->val == root->left->val) {
      ans = max(ans, left);
    } else if (root->right and root->val == root->right->val) {
      ans = max(ans, right);
    }
    return left > right ? left : right;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  auto root = string2tree("[1,5,8,9,7,7,8,1,4]");
  cout << sol.longestUnivaluePath(root) << endl;
  delete_tree(root);
  return 0;
}
