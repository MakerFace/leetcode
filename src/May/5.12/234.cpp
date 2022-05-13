/**
 * @file 234.cpp
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
  bool isPalindrome(ListNode* head) {
    if (not head) return true;
    auto p = head, q = head;
    while (q) {
      if (q->next)
        q = q->next->next;
      else
        break;
      p = p->next;
    }
    q = p;
    p = head;
    q = inverse(q);
    while (p->next and q) {
      if (p->val != q->val) {
        return false;
      }
      p = p->next;
      q = q->next;
    }
    return true;
  }

 private:
  ListNode* inverse(ListNode* head) {
    ListNode* result = nullptr;
    ListNode* temp;
    while (head) {
      if (not result) {
        result = head;
        head = head->next;
        result->next = nullptr;
        continue;
      }
      temp = head->next;
      head->next = result;
      result = head;
      head = temp;
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  auto head = vector2list({1, 2});
  std::cout << boolalpha << ans.isPalindrome(head) << std::endl;
  print_list(head);
  return 0;
}
