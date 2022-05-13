/**
 * @file 206.cpp
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
  ListNode* reverseList(ListNode* head) {
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
  auto head = vector2list({});
  auto res = ans.reverseList(head);
  print_list(res);
  return 0;
}
