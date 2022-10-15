/**
 * @file 236.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-13
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    flag = false;
    ancestor = nullptr;
    dfs(root, p, q);
    return ancestor;
  }

 private:
  int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (not root) return 0;
    int count = dfs(root->left, p, q);
    count += dfs(root->right, p, q);
    count += (root->val == p->val) + (root->val == q->val);
    if (not flag and count == 2) {
      flag = true;
      ancestor = root;
    }
    return count;
  }

 private:
  bool flag;
  TreeNode* ancestor;
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.14/236.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto root = string2tree(s);
    in.getline(buf, MAX_LINE_SIZE);
    auto n = atoi(buf);
    auto p = find_in_tree(root, n)[0];
    in.getline(buf, MAX_LINE_SIZE);
    n = atoi(buf);
    auto q = find_in_tree(root, n)[0];
    auto ans = sol.lowestCommonAncestor(root, p, q);
    std::cout << ans->val << std::endl;
    delete_tree(root);
  }
  return 0;
}
