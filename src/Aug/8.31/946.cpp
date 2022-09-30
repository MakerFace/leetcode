/**
 * @file 946.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-08-31
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    stack<int> sta;
    size_t j = 0;
    for (int i = 0; i < n; i++) {
      sta.push(pushed[i]);
      while (not sta.empty() and sta.top() == popped[j]) {
        if (sta.empty()) {
          return false;
        }
        sta.pop();
        ++j;
      }
    }
    return j == popped.size();
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<int> pushed({1, 2, 3, 4, 5}), popped({4,5,3,2,1});
  cout << boolalpha << sol.validateStackSequences(pushed, popped) << endl;
  return 0;
}
