/**
 * @file 160.cpp
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p = headA, *q = headB;
    while (p and q) {
      if (p == q) return p;
      p = p->next;
      q = q->next;
      if (not p and q) p = headB;
      if (not q and p) q = headA;
    }
    return nullptr;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  auto headA = vector2list({4, 1, 8, 4, 5});
  auto headB = vector2list({5, 6, 1, 8, 4, 5});
  auto res = ans.getIntersectionNode(headA, headB);
  std::cout << boolalpha << (res == nullptr) << std::endl;
  return 0;
}
