/**
 * @file 41.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-07
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int> &nums) {
    size_t i = 0, j = nums.size() - 1;
    while (i < nums.size()) {
      if (nums[i] <= 0) {
        nums[i] = nums[j];
        nums[j] = INT_MAX;
        if (j > 0) --j;
      } else if (nums[i] == (int)i + 1) {
        ++i;
      } else {
        if (nums[i] < (int)nums.size() and nums[i] != nums[nums[i] - 1]) {
          swap(nums[i], nums[nums[i] - 1]);
        } else
          ++i;
      }
    }
    i = 0;
    for (; i < nums.size(); ++i) {
      if (nums[i] - 1 != (int)i) return (int)(i + 1);
    }
    return (int)(i + 1);
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  vector<int> nums = {5, 3, -1, 2, 2, 1, 4};
  std::cout << ans.firstMissingPositive(nums) << std::endl;
  return 0;
}
