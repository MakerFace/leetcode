/**
 * @file 6235.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-13
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <iterator>
#include <queue>
#include <unordered_map>
#include <vector>

#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 public:
  int minimumOperations(TreeNode* root) {
    queue<TreeNode*> que;
    int ans = 0;
    que.emplace(root);
    while (not que.empty()) {
      const int n = que.size();
      vector<int> nums;
      for (int i = 0; i < n; ++i) {
        auto front = que.front();
        nums.emplace_back(front->val);
        if (front->left) {
          que.emplace(front->left);
        }
        if (front->right) {
          que.emplace(front->right);
        }
        que.pop();
      }
      unordered_map<int, int> map;
      auto sorted = nums;
      sort(sorted.begin(), sorted.end());
      for (int i = 0; i < n; ++i) {
        map[sorted[i]] = i;
      }
      vector<int> flags(n, 0);
      int lops = 0;
      for (int i = 0; i < n; ++i) {
        if (not flags[i]) {
          int j = i;
          while (not flags[j]) {
            flags[j] = true;
            j = map[nums[j]];
          }
          lops++;
        }
      }
      ans += n - lops;
    }
    return ans;
  }

  vector<int> tmp;
  int get(vector<int>& nums) {
    tmp = vector<int>(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      tmp[i] = i;
    }
    sort(tmp.begin(), tmp.end(),
         [&](int a, int b) -> bool { return nums[a] < nums[b]; });
    int cnt = 0;
    for (int i = 0; i < tmp.size(); i++) {
      if (tmp[i] == i) continue;
      int j = i;
      while (tmp[j] != j) {
        swap(tmp[j], tmp[tmp[j]]);
        cnt++;
      }
    }
    return cnt;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.13/6235.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto root = string2tree(buf);
    auto ans = sol.minimumOperations(root);
    std::cout << ans << std::endl;
    delete_tree(root);
  }
  return 0;
}
