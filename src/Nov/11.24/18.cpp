/**
 * @file 18.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-23
 */

#include <bits/stdc++.h>

#include <algorithm>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    for (int i = 0; i < n; ++i) {  // x
      if (i > 0 and nums[i] == nums[i - 1]) continue;
      for (int j = i + 1; j < n; ++j) {  // y
        if (j > i + 1 and nums[j] == nums[j - 1]) continue;
        int l = n - 1;
        for (int k = j + 1; k < n; ++k) {  // z
          if (k > j + 1 and nums[k] == nums[k - 1]) continue;
          int value = INT_MIN;
          while (l > k) {
            value = nums[i] + nums[j] + nums[k] + nums[l];
            if (value > target) {
              --l;
            } else {
              break;
            }
          }
          if (value == target) {
            ans.emplace_back(vector<int>{nums[i], nums[j], nums[k], nums[l]});
          }
        }
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.24/18.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto target = atoi(buf);
    auto ans = sol.fourSum(nums, target);
    std::cout << ans << std::endl;
  }
  return 0;
}
