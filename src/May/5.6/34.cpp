/**
 * @file 34.cpp
 * @brief 在排序数组中查找元素的第一个和最后一个位置
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.empty()) return vector<int>({-1, -1});
    size_t i = 0, j = nums.size() - 1;
    int mid = 0;
    while (i < j) {
      mid = (i + j) / 2;
      if (nums[mid] > target) {
        j = mid - 1;
      } else if (nums[mid] < target) {
        i = mid + 1;
      } else {
        break;
      }
    }
    if (nums[mid] != target and nums[i] != target) {
      return vector<int>({-1, -1});
    }
    vector<int> result(2);
    i = j = nums[mid] == target ? mid : i;
    while (i > 0 and nums[i - 1] == target) {
      --i;
    }
    while (j < nums.size() - 1 and nums[j + 1] == target) {
      ++j;
    }
    result[0] = i;
    result[1] = j;
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  vector<int> nums = {5};
  int target;
  while (cin >> target) {
    println_vector(ans.searchRange(nums, target));
    std::cout << std::endl;
  }
  return 0;
}
