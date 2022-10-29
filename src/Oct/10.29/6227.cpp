/**
 * @file 6227.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-29
 * ! hello
 * ? why
 */
#include <bits/stdc++.h>

#include "common/Vector.hpp"
using namespace std;

class Solution {
 public:
  vector<int> secondGreaterElement(vector<int>& nums) {
    vector<int> ans;
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.29/6227.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    auto ans = sol.secondGreaterElement(nums);
    std::cout << ans << std::endl;
  }
  return 0;
}
