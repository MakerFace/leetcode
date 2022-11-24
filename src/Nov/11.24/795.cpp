/**
 * @file 795.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-24
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <cstdlib>
#include <unordered_map>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    int point = -1, divide = -1, n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] >= left && nums[i] <= right) point = i;
      if (nums[i] > right) divide = i;
      ans += max(point - divide, 0);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.24/795.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto left = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto right = atoi(buf);
    auto ans = sol.numSubarrayBoundedMax(nums, left, right);
    std::cout << ans << std::endl;
  }
  return 0;
}
