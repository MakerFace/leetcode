/**
 * @file 206.1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-08-28
 */

#include <bits/stdc++.h>

#include "common/ListNode.hpp"
using namespace std;
/**
 * old:
 *  if (head == nullptr) {
      return nullptr;
    }
    if (head->next == NULL) {
      return head;
    }
    auto ans = reverseList(head->next);
    if (ans == nullptr) return nullptr;
    auto temp = ans;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    head->next = temp->next;
    temp->next = head;
    return ans;
 */
class Solution {
 public:
  ListNode* reverseList(ListNode* head) { return reverse_list(nullptr, head); }

 private:
  ListNode* reverse_list(ListNode* pre, ListNode* cur) {
    if (cur == nullptr) return pre;
    auto next = cur->next;
    cur->next = pre;
    return reverse_list(cur, next);
  }
};

int main(int argc, char const* argv[]) {
  auto head = vector2list({1,2,3,4,5});
  Solution sol;
  auto res = sol.reverseList(head);
  print_list(res);
  return 0;
}
