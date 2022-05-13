/**
 * @file 55.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-07
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int> &nums) {
    int max_len = nums[0];
    for (int i = 0; i <= max_len; ++i) {
      if (i + nums[i] > max_len) {
        max_len = i + nums[i];
      }
      if (max_len >= (int)nums.size()) return true;
    }
    return max_len >= (int)nums.size() - 1;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> nums = {2, 3, 1, 1, 4};
  Solution ans;
  std::cout << boolalpha << ans.canJump(nums) << std::endl;
  return 0;
}
