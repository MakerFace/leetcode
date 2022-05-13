/**
 * @file 95.cpp
 * @brief 不同的二叉树II
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-25
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 private:
  vector<int> nums = {1, 2, 5, 14, 42, 132, 429, 1430};

 public:
  vector<TreeNode *> generateTrees(int n) {
    if (n == 1) {
      return vector<TreeNode *>({new TreeNode(n)});
    }
    vector<TreeNode *> result;
    for (int i = 1; i <= n; ++i) {
      auto left = createTree(1, i - 1);
      auto right = createTree(i + 1, n);
      if (left.empty()) {
        for (size_t k = 0; k < right.size(); ++k) {
          TreeNode *root = new TreeNode(i);
          root->right = right[k];
          result.push_back(root);
        }
      }
      if (right.empty()) {
        for (size_t k = 0; k < left.size(); ++k) {
          TreeNode *root = new TreeNode(i);
          root->left = left[k];
          result.push_back(root);
        }
      }
      for (size_t j = 0; j < left.size(); ++j) {
        for (size_t k = 0; k < right.size(); ++k) {
          TreeNode *root = new TreeNode(i);
          root->left = left[j];
          root->right = right[k];
          result.push_back(root);
        }
      }
    }
    return result;
  }

 private:
  vector<TreeNode *> createTree(int start, int end) {
    if (start > end) {
      return vector<TreeNode *>();
    }
    if (start == end) {
      return vector<TreeNode *>({new TreeNode(start)});
    }
    if (end - start == 1) {
      vector<TreeNode *> result(2);
      result[0] = new TreeNode(start);
      result[0]->right = new TreeNode(end);
      result[1] = new TreeNode(end);
      result[1]->left = new TreeNode(start);
      return result;
    }
    vector<TreeNode *> result;
    for (int i = start; i <= end; ++i) {
      auto left = createTree(start, i - 1);
      auto right = createTree(i + 1, end);
      if (left.empty()) {
        for (size_t j = 0; j < right.size(); ++j) {
          TreeNode *root = new TreeNode(i);
          root->right = right[j];
          result.push_back(root);
        }
      }
      if (right.empty()) {
        for (size_t j = 0; j < left.size(); ++j) {
          TreeNode *root = new TreeNode(i);
          root->left = left[j];
          result.push_back(root);
        }
      }
      for (size_t j = 0; j < left.size(); ++j) {
        for (size_t k = 0; k < right.size(); ++k) {
          TreeNode *root = new TreeNode(i);
          root->left = left[j];
          root->right = right[k];
          result.push_back(root);
        }
      }
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  int n;
  while (cin >> n) {
    auto res = ans.generateTrees(n);
    for (auto r : res) {
      println_tree(r);
    }
  }
  return 0;
}
