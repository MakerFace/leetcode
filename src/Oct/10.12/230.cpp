/**
 * @file 230.cpp
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
  int kthSmallest(TreeNode* root, int k) {
    this->k = k;
    bfs(root);
    return pq.top();
  }

 private:
  void bfs(TreeNode* root) {
    if (not root) return;
    queue<TreeNode*> que;
    que.emplace(root);
    while (not que.empty()) {
      auto top = que.front();
      que.pop();
      if (top->left) que.emplace(top->left);
      if (top->right) que.emplace(top->right);
      pq.push(top->val);
      while (k < static_cast<int>(pq.size())) pq.pop();
    }
  }

  void dfs(TreeNode* root) {
    if (not root) return;
    pq.push(root->val);
    if (static_cast<int>(pq.size()) > k) {
      pq.pop();
    }
    dfs(root->left);
    dfs(root->right);
  }

 private:
  int k;
  priority_queue<int> pq;
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.12/230.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto root = string2tree(s);
    in.getline(buf, MAX_LINE_SIZE);
    s = buf;
    auto k = atoi(s.c_str());
    auto ans = sol.kthSmallest(root, k);
    std::cout << ans << std::endl;
    delete_tree(root);
  }
  return 0;
}
