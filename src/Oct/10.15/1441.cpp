/**
 * @file 1441.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-15
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ans;
    int j = 0;
    int m = static_cast<int>(target.size());
    for (int i = 1; i <= n and j < m; ++i) {
      if (i == target[j]) {
        ans.emplace_back("Push");
        ++j;
      } else {
        ans.emplace_back("Push");
        ans.emplace_back("Pop");
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.15/1441.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto target = string2vector(s);
    in.getline(buf, MAX_LINE_SIZE);
    auto n = atoi(buf);
    auto ans = sol.buildArray(target, n);
    std::cout << ans << std::endl;
  }
  return 0;
}
