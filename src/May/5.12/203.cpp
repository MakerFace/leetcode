/**
 * @file 203.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>

#include "common/ListNode.hpp"
using namespace std;

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    if (not head) return nullptr;
    while (head and head->val == val) {
      head = head->next;
    }
    ListNode* p = head;
    while (p) {
      if (p->next and p->next->val == val) {
        p->next = p->next->next;
      } else {
        p = p->next;
      }
    }
    return head;
  }
};

int main(int argc, char const* argv[]) {
  auto head = vector2list({1, 2, 6, 3, 4, 5, 6});
  Solution ans;
  int val;
  while (cin >> val) {
    auto res = ans.removeElements(head, val);
    print_list(res);
  }

  return 0;
}
