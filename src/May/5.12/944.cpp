/**
 * @file 944.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int result = 0;
    int n = strs.size();
    int m = strs[0].size();
    for (int j = 0; j < m; ++j) {
      int i;
      for (i = 1; i < n; ++i) {
        if (strs[i][j] < strs[i - 1][j]) {
          break;
        }
      }
      if (i != n) ++result;
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  vector<string> strs = {"zyx", "wvu", "tsr"};
  std::cout << ans.minDeletionSize(strs) << std::endl;
  return 0;
}
