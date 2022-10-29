/**
 * @file test3.cpp
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
  int minimizeArrayValue(vector<int>& nums) {
    int ans = INT_MIN;
    int n = static_cast<int>(nums.size());
    for (int i = 1; i < n; i++) {
      int sum = nums[i - 1];
      int j = i;
      while (j < n and nums[j] >= nums[j - 1]) {
        sum += nums[j];
        ++j;
      }
      if (i != j) {
        nums[i - 1] = sum / (j - i + 1);
        sum %= (j - i + 1);
        for (int k = 0; k <= sum; k++) {
          nums[j - k - 1] = nums[i - 1] + 1;
        }
        ans = max(ans, nums[j - 1]);
      }
      i = j;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.15/test3.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto nums = string2vector(s);
    auto ans = sol.minimizeArrayValue(nums);
    std::cout << ans << std::endl;
  }
  return 0;
}
