/**
 * @file 199.cpp
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
  vector<int> rightSideView(TreeNode* root) {
    study.clear();
    bfs(root);
    return study;
  }

 private:
  void dfs(TreeNode* root, size_t deep) {
    if (not root) return;
    if (deep == study.size())
      study.emplace_back(root->val);
    else
      study[deep] = root->val;
    dfs(root->left, deep + 1);
    dfs(root->right, deep + 1);
  }

  void bfs(TreeNode* root) {
    if (not root) return;
    int deep = 0;
    queue<TreeNode*> que;
    que.emplace(root);
    while (not que.empty()) {
      int len = que.size();
      auto top = que.front();
      for (int i = 0; i < len; i++) {
        top = que.front();
        que.pop();
        if (top->left) que.emplace(top->left);
        if (top->right) que.emplace(top->right);
        if (i == len - 1) {
          if (deep >= static_cast<int>(study.size()))
            study.emplace_back(top->val);
          else
            study[deep] = top->val;
        }
      }
      ++deep;
    }
  }

 private:
  vector<int> study;
};

int main(int argc, char const* argv[]) {
  Solution sol;
  string s = string(PROJECT_PATH).append("/src/Oct/10.11/199.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    s = buf;
    auto root = string2tree(s);
    auto ans = sol.rightSideView(root);
    std::cout << ans << std::endl;
    delete_tree(root);
  }
  return 0;
}
