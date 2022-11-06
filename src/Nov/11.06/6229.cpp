/**
 * @file 6229.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-06
 */
#include <bits/stdc++.h>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  vector<int> applyOperations(vector<int>& nums) {
    for (int i = 0, j = 0; i < nums.size() - 1; ++i) {
      if (nums[i] == nums[i + 1]) {
        nums[i] <<= 1;
        nums[i + 1] = 0;
      }
    }
    int i = 0, j = 0;
    while (j < nums.size()) {
      while (j < nums.size() and nums[j] == 0) ++j;
      if (j >= nums.size()) {
        break;
      }
      nums[i++] = nums[j++];
    }
    while (i < nums.size()) {
      nums[i++] = 0;
    }
    return nums;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.06/6229.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    auto ans = sol.applyOperations(nums);
    std::cout << ans << std::endl;
  }
  return 0;
}
