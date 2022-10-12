/**
 * @file 222.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-12
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  int countNodes(TreeNode* root) { return bfs(root); }

 private:
  int dfs(TreeNode* root) {
    if (not root) return 0;
    return 1 + dfs(root->left) + dfs(root->right);
  }

  int bfs(TreeNode* root) {
    if (not root) return 0;
    int count = 0;
    queue<TreeNode*> que;
    que.emplace(root);
    while (not que.empty()) {
      auto top = que.front();
      if (top->left) que.emplace(top->left);
      if (top->right) que.emplace(top->right);
      que.pop();
      ++count;
    }
    return count;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  string s = string(PROJECT_PATH).append("/src/Oct/10.12/222.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    s = buf;
    auto root = string2tree(s);
    auto ans = sol.countNodes(root);
    std::cout << ans << std::endl;
    delete_tree(root);
  }
  return 0;
}
