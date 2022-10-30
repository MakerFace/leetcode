/**
 * @file 337.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-29
 */
#include <algorithm>
#include <fstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <vector>

#include "common/TreeNode.hpp"
#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int rob(TreeNode* root) {
    unordered_map<TreeNode*, int> select, noselect;
    stack<pair<TreeNode*, int>> sta;
    // 后续遍历
    auto p = root;
    while (p or not sta.empty()) {
      if (p) {
        sta.emplace(p, 1);
        p = p->left;
      } else {
        auto& top = sta.top();
        top.second++;
        if (top.second == 3) {
          select[top.first] = top.first->val + noselect[top.first->left] +
                              noselect[top.first->right];
          noselect[top.first] =
              max(select[top.first->left], noselect[top.first->left]) +
              max(noselect[top.first->right], select[top.first->right]);
          sta.pop();
        } else {
          p = top.first->right;
        }
      }
    }
    return max(select[root], noselect[root]);
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.29/337.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto root = string2tree(buf);
    auto ans = sol.rob(root);
    std::cout << ans << std::endl;
    delete_tree(root);
  }
  return 0;
}
