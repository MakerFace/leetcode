/**
 * @file 769.cpp
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
  int maxChunksToSorted(vector<int>& arr) {
    int ans = 0;
    int max_val = 0;
    int len = 0;
    for (auto& a : arr) {
      max_val = max(max_val, a);
      if (max_val == len) {
        ans++;
      }
      ++len;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.13/769.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto arr = string2vector(s);
    auto ans = sol.maxChunksToSorted(arr);
    std::cout << ans << std::endl;
  }
  return 0;
}
