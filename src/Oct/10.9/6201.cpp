/**
 * @file 6201.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-09
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> findArray(vector<int>& pref) {
    vector<int> ans(pref.size());
    ans[0] = pref[0];
    for (size_t i = 1; i < pref.size(); i++) {
      ans[i] = pref[i] ^ pref[i - 1];
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<int> pref{5, 2, 0, 3, 1};
  auto ans = sol.findArray(pref);
  for (auto var : ans) {
    std::cout << var << std::endl;
  }

  return 0;
}
