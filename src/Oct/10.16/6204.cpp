/**
 * @file 6204.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-16
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  int findMaxK(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i = 0, j = static_cast<int>(nums.size() - 1);
    while (i < j) {
      if (-nums[i] == nums[j]) {
        return nums[j];
      } else if (-nums[i] > nums[j]) {
        i++;
      } else {
        --j;
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.15/6204.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto nums = string2vector(s);
    auto ans = sol.findMaxK(nums);
    std::cout << ans << std::endl;
  }
  return 0;
}
