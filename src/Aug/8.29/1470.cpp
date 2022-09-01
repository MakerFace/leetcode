/**
 * @file 1470.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-08-29
 */

#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> res(2 * n);
    for (int i = 0, j = 0; i < n; i++, j += 2) {
      res[j] = nums[i];
      res[j + 1] = nums[i + n];
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<int> nums({1, 2, 3, 4, 4, 3, 2, 1});
  print_vector(sol.shuffle(nums, 4));
  return 0;
}
