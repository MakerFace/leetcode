/**
 * @file 965.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-24
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 public:
  bool isUnivalTree(TreeNode* root) {
    int val = root->val;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while (p or not s.empty()) {
      if (p) {
        while (p) {
          s.push(p);
          p = p->left;
        }
      } else {
        p = s.top();
        s.pop();
        if (p->val != val) {
          return false;
        }
        p = p->right;
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  auto root = string2tree("[1,1,1,1,1,null,1]");
  std::cout << boolalpha << ans.isUnivalTree(root) << std::endl;
  return 0;
}
