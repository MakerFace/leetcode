/**
 * @file 237.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-22
 */
#include <bits/stdc++.h>

#include "common/ListNode.hpp"
using namespace std;

class Solution {
 public:
  void deleteNode(ListNode* node) {
    swap(node->val, node->next->val);
    node->next = node->next->next;
  }
};

int main(int argc, char const* argv[]) { return 0; }
