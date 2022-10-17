/**
 * @file 437.cpp
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
  int pathSum(TreeNode* root, int targetSum) {
    ans = 0;
    count = 0;
    this->targetSum = targetSum;
    map[0] = 1;
    dfs(root);
    return ans;
  }

 private:
  void dfs(TreeNode* root) {
    if (not root) return;
    count += root->val;
    auto res = map.find(count - targetSum);
    if (res != map.end()) ans += res->second;
    map[count]++;
    dfs(root->left);
    dfs(root->right);
    map[count]--;
    count -= root->val;
  }

 private:
  int ans, targetSum;
  int count;
  unordered_map<long long, int> map;
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.13/437.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto root = string2tree(s);
    in.getline(buf, MAX_LINE_SIZE);
    auto targetSum = atoi(buf);
    auto ans = sol.pathSum(root, targetSum);
    std::cout << ans << std::endl;
    delete_tree(root);
  }
  return 0;
}
