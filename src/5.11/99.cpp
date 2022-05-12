/**
 * @file 99.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-11
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"

using namespace std;

class Solution {
 public:
  void recoverTree(TreeNode* root) {
    TreeNode *p, *q = nullptr;
    TreeNode *temp1, *temp2;
    stack<TreeNode*> s;
    p = root;
    while (not s.empty() or p) {
      if (p) {
        while (p) {
          s.push(p);
          p = p->left;
        }
      } else {
        if (not q) {
          q = s.top();
        }
        p = s.top();
        if (p->val < q->val) {  // find first reverse node
          p = p->right;
          temp1 = q;
          q = s.top();
          break;
        } else {
          q = p;
        }
        s.pop();
        p = p->right;
      }
    }
    while (not s.empty() or p) {
      if (p) {
        while (p) {
          s.push(p);
          p = p->left;
        }
      } else {
        p = s.top();
        s.pop();
        if (p->val > temp1->val) {  // find first reverse node
          break;
        } else {
          q = p;
        }
        p = p->right;
      }
    }
    temp2 = q;
    swap(temp1->val, temp2->val);
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  string str;
  while (cin >> str) {
    auto root = string2tree(str);
    ans.recoverTree(root);
    print_tree(root);
  }
  return 0;
}
