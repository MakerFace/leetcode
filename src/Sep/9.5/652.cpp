/**
 * @file 652.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-05
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    preOrder(root);
    return ans;
  }

 private:
  void preOrder(TreeNode* root) {
    if (not root) {
      return;
    }
    string seq;
    tree2string(root, seq);
    if (map.find(seq) == map.end()) {
      map[seq] = make_tuple(root, 1);
    } else {
      auto& t = map[seq];
      if (get<1>(t) == 1) {
        ans.push_back(get<0>(t));
        get<1>(t)++;
      }
    }
    preOrder(root->left);
    preOrder(root->right);
  }

  void tree2string(TreeNode* t, string& seq) {
    if (not t) {
      seq += "^";
      return;
    }
    seq += to_string(t->val) + ",";
    tree2string(t->left, seq);
    tree2string(t->right, seq);
  }

 private:
  vector<TreeNode*> ans;
  unordered_map<string, tuple<TreeNode*, int>> map;
};

int main(int argc, char const* argv[]) {
  Solution sol;
  auto root = string2tree("[1,2,3,4,null,2,4,null,null,4]");
  auto ans = sol.findDuplicateSubtrees(root);
  cout << "[";
  for (auto& t : ans) {
    print_tree(t);
  }
  cout << "]" << endl;
  delete_tree(root);
  return 0;
}
