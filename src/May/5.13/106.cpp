/**
 * @file 106.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-13
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 private:
  using v_iter_t = vector<int>::iterator;
  using v_riter_t = vector<int>::reverse_iterator;

 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildChild(postorder.rbegin(), postorder.rend(), inorder.begin(),
                      inorder.end());
  }

 private:
  TreeNode* buildChild(v_riter_t postorder_rs, v_riter_t postorder_re,
                       v_iter_t inorder_s, v_iter_t inorder_e) {
    TreeNode* root = nullptr;
    if (postorder_rs != postorder_re) {
      auto in_i = inorder_s;
      auto post_i = postorder_re;
      while (in_i != inorder_e and *in_i != *postorder_rs) {
        ++in_i;
        --post_i;
      }
      root = new TreeNode(
          *postorder_rs, buildChild(post_i, postorder_re, inorder_s, in_i),
          buildChild(postorder_rs + 1, post_i, in_i + 1, inorder_e));
    }
    return root;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> inorder{7, 6, 5, 4, 3, 2, 1}, postorder{1, 2, 3, 4, 5, 6, 7};
  Solution ans;
  auto root = ans.buildTree(inorder, postorder);
  println_tree(root);
  return 0;
}
