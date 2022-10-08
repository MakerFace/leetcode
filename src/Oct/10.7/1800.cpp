/**
 * @file 1800.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-07
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxAscendingSum(vector<int>& nums) {
    int ans = 0;
    int sum = nums[0];
    int n = static_cast<int>(nums.size());
    for (int i = 1; i < n; i++) {
      ans = max(ans, sum);
      if (nums[i] > nums[i - 1]) {
        sum += nums[i];
      } else {
        sum = nums[i];
      }
    }
    ans = max(ans, sum);
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<int> nums;
  int n;
  while (cin >> n) {
    nums.push_back(n);
  }

  std::cout << sol.maxAscendingSum(nums) << std::endl;
  return 0;
}