/**
 * @file 6207.cpp
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
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long left = 0, min_idx = 0, max_idx = 0;
    long long n = static_cast<long long>(nums.size());
    vector<long long> dp(n + 1, 0);
    for (long long i = 0; i < n; ++i) {
      if (nums[i] < minK or nums[i] > maxK) {
        left = min_idx = max_idx = i + 1;  // 这个是边界起点
        dp[i + 1] = dp[i];
      } else {
        if (nums[i] == minK or nums[i] == maxK) {
          if (nums[i] == minK) {
            min_idx = i;
            // 计算加入最小值后，最大值前有多少个数
            if (nums[max_idx] == maxK)
              dp[min_idx + 1] = dp[i] + max_idx - left + 1;
            else
              dp[i + 1] = dp[i];
          }
          if (nums[i] == maxK) {
            max_idx = i;
            // 计算加入一个最大值后，最小值前有多少个合法数
            if (nums[min_idx] == minK)
              dp[max_idx + 1] = dp[i] + min_idx - left + 1;
            else
              dp[i + 1] = dp[i];
          }
        } else if (nums[i] > minK and nums[i] < maxK) {
          if (nums[min_idx] == minK and nums[max_idx] == maxK)
            dp[i + 1] = dp[i] + min(min_idx, max_idx) - left + 1;
          else
            dp[i + 1] = dp[i];
        }
      }
    }
    return dp[n];
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.15/6207.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto nums = string2vector(s);
    in.getline(buf, MAX_LINE_SIZE);
    auto minK = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto maxK = atoi(buf);
    // for (auto n : nums) {
    //   std::cout << n - minK << std::endl;
    // }
    // exit(0);
    auto ans = sol.countSubarrays(nums, minK, maxK);
    std::cout << ans << std::endl;
  }
  return 0;
}
