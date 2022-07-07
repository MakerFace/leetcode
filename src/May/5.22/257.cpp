/**
 * @file 257.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-22
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<pair<TreeNode*, int>> s;
    vector<string> result;
    auto p = root;
    while (p or not s.empty()) {
      if (p) {
        while (p) {
          s.emplace_back(make_pair(p, 0));
          p = p->left;
        }
      } else {
        auto& t = *(s.end() - 1);
        t.second++;
        p = t.first;
        if (t.second == 2) {
          if (p->left == nullptr and p->right == nullptr) {
            string str;
            for (size_t i = 0; i < s.size(); i++) {
              str += to_string(s[i].first->val) + "->";
            }
            result.emplace_back(str.substr(0, str.size() - 2));
          }
          s.erase(s.end() - 1);
          p = nullptr;
        } else {
          p = p->right;
        }
      }
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  auto root = string2tree("[1,2,3,4,5,6,7]");
  println_vector(ans.binaryTreePaths(root));
  return 0;
}
