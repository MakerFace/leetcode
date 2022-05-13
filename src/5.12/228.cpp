/**
 * @file 228.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    for (size_t i = 0; i < nums.size(); ++i) {
      size_t j = i;
      while (i + 1 < nums.size()) {
        if (nums[i + 1] - 1 > nums[i]) {
          break;
        }
        ++i;
      }
      if (i != j) {
        result.push_back(to_string(nums[j]) + "->" + to_string(nums[i]));
      } else {
        result.push_back(to_string(nums[i]));
      }
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  vector<int> nums{-2147483648, -2147483647, 2147483647};
  auto res = ans.summaryRanges(nums);
  println_vector(res);
  return 0;
}
