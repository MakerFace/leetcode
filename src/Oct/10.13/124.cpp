/**
 * @file 124.cpp
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
  int maxPathSum(TreeNode* root) {
    maxValue = INT_MIN;
    dfs(root);
    return maxValue;
  }

 private:
  /**
   * @brief 计算每个结点的贡献值（最大的左右结点和自己的和）
   * 在计算过程中，计算当前路径（当前结点和左右结点贡献值和）的最大值
   */
  int dfs(TreeNode* root) {
    if (not root) return 0;
    auto left = max(dfs(root->left), 0);
    auto right = max(dfs(root->right), 0);
    auto temp = root->val + left + right;  // cur_path = val + left + right
    maxValue = max(maxValue, temp);
    return root->val + max(left, right);  // 贡献值score=val+max(left, right)
  }

 private:
  int maxValue;
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.13/124.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto root = string2tree(s);
    auto ans = sol.maxPathSum(root);
    std::cout << ans << std::endl;
    delete_tree(root);
  }
  return 0;
}
