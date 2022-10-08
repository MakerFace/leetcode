/**
 * @file fall-5.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-07
 */
#include <bits/stdc++.h>

#include "common/Matrix.hpp"
using namespace std;

class Solution {
 public:
  vector<vector<int>> sandyLandManagement(int size) {
    deque<vector<int>> ans;
    int i = size;
    for (; i >= 2; --i) {
      for (int j = i * 2 - 1; j >= 1; j -= 2) {
        ans.emplace_front(vector<int>{i, j});
        if (i == 2) break;
      }
      --i;
      if (i <= 1) break;
      ans.emplace_front(vector<int>{i, 2});
      --i;
      if (i <= 1) break;
      for (int j = i * 2 - 1; j >= 3; j -= 2) {
        ans.emplace_front(vector<int>{i, j});
      }
    }
    if (i == 1) ans.emplace_front(vector<int>{1, 1});

    vector<vector<int>> result(ans.size());
    copy(ans.begin(), ans.end(), result.begin());
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  int n;
  while (cin >> n) {
    auto ans = sol.sandyLandManagement(n);
    println_matrix(ans);
  }
  return 0;
}
