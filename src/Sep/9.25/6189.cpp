/**
 * @file 6188.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-25
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int max_n = 0;
    int count = 0;
    int ans = 0;
    for (auto& n : nums) {
      if (max_n < n) {
        count = 1;
        max_n = n;
        ans = 0;
      } else if (max_n == n) {
        ++count;
      } else {
        count = 0;
      }
      ans = max(ans, count);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<int> nums{311155, 311155, 311155, 311155, 311155,
                   311155, 311155, 311155, 201191, 311155};
  auto ans = sol.longestSubarray(nums);
  std::cout << ans << std::endl;
  return 0;
}
