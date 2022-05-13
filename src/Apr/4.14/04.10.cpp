/**
 * @file 04.10.cpp
 * @brief 检查子树
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-14
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool checkSubTree(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr && t2 == nullptr) {
      return true;
    }
    if (t1 == nullptr || t2 == nullptr) {
      return false;
    }
    if (t1->val == t2->val) {
      if (!checkSubTree(t1->left, t2)) return checkSubTree(t1->right, t2);
    } else if (t1->val != t2->val) {
    }
    return false;
  }
};

TreeNode *vector2tree(vector<int> &vec, int s = 0) {
  if (vec[s] == '#') {
    return nullptr;
  }
  TreeNode *root = new TreeNode(vec[s]);
  return root;
}

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> tree1 = {1, '#', 2, 4};
  vector<int> tree2 = {3, 2};
  TreeNode *t1 = vector2tree(tree1);
  TreeNode *t2 = vector2tree(tree2);
  auto res = s.checkSubTree(t1, t2);
  std::cout << boolalpha << res << std::endl;
  return 0;
}
