/**
 * @file 6176.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-11
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int mostFrequentEven(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int max_count = -1;
    int n = nums.size();
    int ans = -1;
    for (int i = 0; i < n; i++) {
      int count = nums[i] % 2 == 0;
      while (count and i + 1 < n and nums[i] == nums[i + 1]) {
        ++count;
        ++i;
      }
      if (count > 0 and count > max_count) {
        max_count = count;
        ans = nums[i];
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{1000, 1000, 1000};
  Solution sol;
  std::cout << sol.mostFrequentEven(nums) << std::endl;
  return 0;
}
