/**
 * @file 109.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-11
 */
#include <bits/stdc++.h>

#include "common/ListNode.hpp"
#include "common/TreeNode.hpp"
using namespace std;

class Solution {
 private:
  TreeNode* root;

 public:
  TreeNode* sortedListToBST(ListNode* head) {
    root = nullptr;
    int n = 0;
    ListNode* p = head;
    while (p) {
      ++n;
      p = p->next;
    }
    root = childTree(head, n);
    return root;
  }

 private:
  TreeNode* childTree(ListNode* head, int n) {
    if (n == 1) {
      return new TreeNode(head->val);
    }
    if (not head or not n) {
      return nullptr;
    }
    TreeNode* root;
    ListNode* mid = head;
    n -= 1;
    int left = n / 2, right = n / 2;
    if (n % 2) {
      ++right;
    }
    for (int i = 0; i < n / 2; ++i) mid = mid->next;
    root = new TreeNode(mid->val);
    root->left = childTree(head, left);
    root->right = childTree(mid->next, right);
    return root;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  int n;
  while (cin >> n) {
    vector<int> nums(n);
    std::cout << "[";
    for (int i = 0; i < n; ++i) {
      nums[i] = i;
      std::cout << i << ",";
    }
    std::cout << "\b]" << std::endl;
    auto head = vector2list(nums);
    auto root = ans.sortedListToBST(head);
    println_tree(root);
  }
  return 0;
}
