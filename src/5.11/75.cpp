/**
 * @file 75.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-11
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

/**
 * @brief 计数排序O(n)版本
 * 只适用于特殊情况，存在负数要补成整数
 * 其他算法：单指针：依次将0,1交换到前面，需要两次遍历
 * 双指针：
 */
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    vector<int> count(3);
    for (auto n : nums) {
      ++count[n];
    }
    for (size_t i = 1; i < count.size(); i++) {
      count[i] += count[i - 1];
    }
    vector<int> temp(nums.size());
    for (int i = nums.size() - 1; i >= 0; --i) {
      temp[--count[nums[i]]] = nums[i];
    }
    for (size_t i = 0; i < temp.size(); ++i) {
      nums[i] = temp[i];
    }
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  vector<int> nums{2, 0, 2, 1, 1, 0};
  ans.sortColors(nums);
  println_vector(nums);
  return 0;
}
