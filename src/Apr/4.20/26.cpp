/**
 * @file 26.cpp
 * @brief 删除有序数组的重复项
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-20
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    size_t cur = 0;
    size_t pre = 0;
    size_t next = 0;
    while (next < nums.size()) {
      nums[cur++] = nums[next];
      while (next < nums.size() && nums[pre] == nums[next]) {
        ++next;
      }
      pre = next;
    }
    return cur;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> nums = {1};
  auto res = s.removeDuplicates(nums);
  nums.resize(res);
  println_vector(nums);
  return 0;
}
