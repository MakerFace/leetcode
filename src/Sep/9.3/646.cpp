/**
 * @file 646.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-03
 */

#include <bits/stdc++.h>

#include "common/Matrix.hpp"
using namespace std;

class Solution {
 public:
  int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(),
         [](const vector<int>& v1, const vector<int>& v2) {
           return v1[1] < v2[1];
         });
    int count = 1;
    int current = pairs[0][1];
    for (size_t i = 1; i < pairs.size(); ++i) {
      {
        if (current < pairs[i][0]) {
          ++count;
          current = pairs[i][1];
        }
      }
    }
    return count;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<vector<int>> pairs({{2, 3}, {1, 2}, {3, 4}});
  cout << sol.findLongestChain(pairs) << endl;
  return 0;
}
