/**
 * @file 25.1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-08-31
 */

#include <bits/stdc++.h>

#include "common/ListNode.hpp"
using namespace std;

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) return head;
    /***********用hair指向head，合并循环**********/
    // auto hair = new ListNode();
    // hair->next = head;
    // delete hair; // 最后做
    auto tail = head;
    for (int i = 1; i < k && tail != nullptr; i++) {
      auto new_head = tail->next;
      if (new_head == nullptr) {
        break;
      }
      tail->next = new_head->next;
      new_head->next = head;
      head = new_head;
    }
    /*********************/
    auto ptr = tail;
    while (ptr != nullptr) {
      auto tail = ptr->next;
      int count = 0;
      while (tail != nullptr) {
        tail = tail->next;
        ++count;
        if (count >= k) break;
      }
      if (count < k) {
        break;
      }
      tail = ptr->next;
      for (int i = 1; i < k && tail != nullptr; i++) {
        auto new_head = tail->next;
        tail->next = new_head->next;
        new_head->next = ptr->next;
        ptr->next = new_head;
      }
      ptr = tail;
    }
    return head;
  }
};

int main(int argc, char const* argv[]) {
  auto head = vector2list({1, 2, 3, 4, 5});
  Solution sol;
  print_list(sol.reverseKGroup(head, 2));
  return 0;
}
