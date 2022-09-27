/**
 * @file 6188.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-25
 */

#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<int> mask(names.size());
    iota(mask.begin(), mask.end(), 0);
    sort(mask.begin(), mask.end(),
         [&](const int& a, const int& b) { return heights[a] > heights[b]; });
    vector<string> ans(names.size());
    int i = 0;
    for (auto& m : mask) {
      ans[i] = names[m];
      ++i;
    }

    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<string> names{"Mary", "John", "Emma"};
  vector<int> heights{180, 165, 170};
  auto ans = sol.sortPeople(names, heights);
  println_vector(ans);
  return 0;
}
