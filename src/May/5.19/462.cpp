/**
 * @file 462.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-19
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minMoves2(vector<int>& nums) {
    int mid = 0;
    sort(nums.begin(), nums.end());
    if (nums.size() % 2)
      mid = nums[nums.size() / 2];
    else
      mid = (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2;
    int count = 0;
    for (auto n : nums) {
      count += abs(n - mid);
    }
    return count;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums = {1,  2,  4,  7,  19, 5,  8,  12, 100, 102, 50,
                      47, 23, 89, 55, 67, 19, 2,  40, 10,  3,   20,
                      23, 56, 67, 90, 25, 72, 86, 10, 2, 9};
  Solution ans;
  auto res = ans.minMoves2(nums);
  std::cout << res << std::endl;
  return 0;
}
