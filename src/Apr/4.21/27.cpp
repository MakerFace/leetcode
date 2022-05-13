/**
 * @file 27.cpp
 * @brief 移除元素
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-21
 */

#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  int removeElement(vector<int> &nums, int val) {
    size_t pre = 0;
    size_t next = 0;
    while (next < nums.size()) {
      if (nums[next] != val) {
        nums[pre] = nums[next];
        ++pre;
      }
      ++next;
    }
    nums.resize(pre);
    return pre;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;
  std::cout << s.removeElement(nums, val) << std::endl;
  println_vector(nums);
  return 0;
}
