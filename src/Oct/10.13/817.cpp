/**
 * @file 817.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-13
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  int numComponents(ListNode* head, vector<int>& nums) {
    unordered_set<int> set;
    for (auto& n : nums) {
      set.insert(n);
    }

    auto p = head;
    int ans = 0;
    int flag = false;
    while (p) {
      if (not flag and set.count(p->val) != 0) { // 在集合中
        flag = true;
        ans++;
      }
      if (set.count(p->val) == 0) {  // 不在集合中
        flag = false;
      }
      p = p->next;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.13/817.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto head = string2list(s);
    in.getline(buf, MAX_LINE_SIZE);
    s = buf;
    auto nums = string2vector(s);
    auto ans = sol.numComponents(head, nums);
    std::cout << ans << std::endl;
    delete_list(head);
  }
  return 0;
}
