/**
 * @file 6180.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-18
 */

#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    queue<TreeNode*> nodeq;
    queue<TreeNode*> candq;
    stack<int> vals;
    nodeq.emplace(root);
    int len = 1;
    int flag = false;
    while (not nodeq.empty()) {
      for (int i = 0; i < len; i++) {
        if (flag) {
          candq.emplace(nodeq.front());
          vals.emplace(nodeq.front()->val);
        }
        if (nodeq.front()->left) {
          nodeq.emplace(nodeq.front()->left);
          nodeq.emplace(nodeq.front()->right);
        }
        nodeq.pop();
      }
      len = nodeq.size();
      while (flag and not vals.empty()) {
        candq.front()->val = vals.top();
        vals.pop();
        candq.pop();
      }
      flag = !flag;
    }
    return root;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  auto root = string2tree("[0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]");
  auto ans = sol.reverseOddLevels(root);
  std::cout << ans << std::endl;
  delete_tree(root);
  return 0;
}
