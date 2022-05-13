/**
 * @file offer.023.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-20
 */

#include <bits/stdc++.h>

#include <common/ListNode.hpp>

using namespace std;

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    bool intersection = false;
    ListNode *res = nullptr;
    ListNode *rootB = headB;
    while (headA != nullptr || headB != nullptr) {
      if (headA == headB) {
        if (!intersection) res = headA;
        intersection = true;
        headA = headA->next;
        headB = headB->next;
      } else if (headA != headB) {
        intersection = false;
        headA = headA->next;
        headB = headB->next;
      }
      if (headA == nullptr && headB != nullptr) {
        intersection = false;
        res = nullptr;
        if (headA == nullptr) headA = rootB;
        if (headB == nullptr) headB = rootB;
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  ListNode *listA = vector2list({4, 1, 8, 4, 5});
  ListNode *listB = vector2list({5, 0, 1, 8, 4, 5});
  auto res = s.getIntersectionNode(listA, listB);
  if (res != nullptr) std::cout << res->val << std::endl;
  return 0;
}
