/**
 * @file 6180.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-18
 */

#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
  struct Node {
    int val;
    Node* next[26]{nullptr};
    Node(int val = 0) : val(val) {}
  };

 public:
  vector<int> sumPrefixScores(vector<string>& words) {
    Node root;
    vector<int> ans(words.size());
    for (auto& word : words) {
      Node* p = &root;
      for (auto& ch : word) {
        if (not p->next[ch - 'a']) {
          p->next[ch - 'a'] = new Node();
        }
        p->next[ch - 'a']->val++;
        p = p->next[ch - 'a'];
      }
    }
    int idx = 0;
    for (auto& word : words) {
      Node* p = &root;
      for (auto& ch : word) {
        ans[idx] += p->next[ch - 'a']->val;
        p = p->next[ch - 'a'];
      }
      ++idx;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<string> n{"abc", "ab", "bc", "b"};
  auto ans = sol.sumPrefixScores(n);
  println_vector(ans);
  return 0;
}
