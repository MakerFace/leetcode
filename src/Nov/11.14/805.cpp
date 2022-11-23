/**
 * @file 805.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-14
 */
#include <bits/stdc++.h>

#include <numeric>
#include <unordered_set>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  bool splitArraySameAverage(vector<int> &nums) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    const int len = nums.size();
    if (len == 1) {
      return false;
    }
    for_each(nums.begin(), nums.end(),
             [sum, len](int &n) { n = n * len - sum; });
    unordered_set<int> left;
    for (int i = 1; i < (1 << (len / 2)); ++i) {
      int tot = 0;
      for (int j = 0; j < len / 2; ++j) {
        if (i & (1 << j)) tot += nums[j];
      }
      if (not tot) {  // 和为0，满足要求
        return true;
      }
      left.emplace(tot);
    }
    int rsum = accumulate(nums.begin() + len / 2, nums.end(), 0);
    for (int i = 1; i < (1 << (len - (len / 2))); ++i) {
      int tot = 0;
      for (int j = len / 2; j < len; ++j) {
        if (i & (1 << (j - len / 2))) tot += nums[j];
      }
      if (not tot or (rsum != tot and left.count(-tot))) {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.14/805.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    auto ans = sol.splitArraySameAverage(nums);
    std::cout << ans << std::endl;
  }
  return 0;
}
