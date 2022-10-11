/**
 * @file 129.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-11
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  int sumNumbers(TreeNode* root) {
    // function<int(TreeNode*, int)> dfs;
    // dfs = [&](TreeNode* root, int ans) -> int {
    //   if (root == nullptr) return 0;
    //   ans *= 10;
    //   ans += root->val;
    //   if (root->left == root->right) return ans;
    //   return dfs(root->left, ans) + dfs(root->right, ans);
    // };
    // return dfs(root, 0);
    // function<int(void)> bfs = [&]() -> int {

    /////////////////////bfs////////////////////////
    int ans = 0;
    queue<pair<TreeNode*, int>> nodes;
    nodes.emplace(root, root->val);
    while (not nodes.empty()) {
      auto top = nodes.front();
      nodes.pop();
      if (top.first->left == top.first->right) ans += top.second;
      if (top.first->left)
        nodes.emplace(top.first->left, top.second * 10 + top.first->left->val);
      if (top.first->right)
        nodes.emplace(top.first->right,
                      top.second * 10 + top.first->right->val);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  string s = string(PROJECT_PATH).append("/src/Oct/10.11/129.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    s = buf;
    auto root = string2tree(s);
    auto ans = sol.sumNumbers(root);
    std::cout << ans << std::endl;
    delete_tree(root);
  }
  return 0;
}
