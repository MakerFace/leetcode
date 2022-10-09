/**
 * @file 105.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-13
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

/**
 * @brief 分治，如果节点过多也可以用栈实现
 */
class Solution {
  using v_iter_t = vector<int>::iterator;

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildChild(preorder.begin(), preorder.end(), inorder.begin(),
                      inorder.end());
  }

 private:
  TreeNode* buildChild(v_iter_t preorder_s, v_iter_t preorder_e,
                       v_iter_t inorder_s, v_iter_t inorder_e) {
    TreeNode* root = nullptr;
    if (preorder_s != preorder_e) {
      auto in_i = inorder_s;
      auto pre_i = preorder_s;
      while (in_i != inorder_e and *in_i != *preorder_s) {
        ++in_i;
        ++pre_i;
      }
      root = new TreeNode(*preorder_s);
      root->left = buildChild(preorder_s + 1,
                              pre_i + 1,               // pre[1,i+1)
                              inorder_s, in_i);        // in[0,i)
      root->right = buildChild(pre_i + 1, preorder_e,  // pre[i+1,end)
                               in_i + 1, inorder_e);   // in[i+1,end)
    }
    return root;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  vector<int> preorder{3, 9, 20, 15, 7}, inorder{3, 9, 20, 15, 7};
  Solution ans;
  auto root = ans.buildTree(preorder, inorder);
  std::cout << root << std::endl;
  return 0;
}
