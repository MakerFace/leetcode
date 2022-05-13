/**
 * @file 141.cpp
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
  bool hasCycle(ListNode *head) {
    ListNode *p = head, *q = head;
    while (p and q) {
      p = p->next;
      if (q->next) {
        q = q->next;
      } else {
        return false;
      }
      if (p == q) return true;
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  auto list = vector2list({3, 2, 0, -4});
  std::cout << boolalpha << ans.hasCycle(list) << std::endl;
  return 0;
}
