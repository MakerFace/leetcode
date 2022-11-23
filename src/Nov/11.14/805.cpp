/**
 * @file 805.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-14
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <numeric>

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
    for_each(nums.begin(), nums.end(), [sum, len](int &n) {
      n *= len;
      n -= sum;
    });
    sort(nums.begin(), nums.end());
    auto zero = lower_bound(nums.begin(), nums.end(), 0);
    if (*zero == 0) {
      //* 计算剩余元素和是否为0
      return true;
    }
    int sum_a = nums[0];
    nums.erase(nums.begin());
    while (sum_a) {
      zero = lower_bound(nums.begin(), nums.end(), 0);
      if (sum_a < 0) {
        auto pos_sum_a = lower_bound(zero, nums.end(), -sum_a);
        sum_a += *pos_sum_a;
        nums.erase(pos_sum_a);
      } else {
        auto neg_sum_a = lower_bound(nums.begin(), zero, -sum_a);
        sum_a += *neg_sum_a;
        nums.erase(neg_sum_a);
      }
    }
    if (nums.empty()) {
      return false;
    }
    int sum_b = accumulate(nums.begin(), nums.end(), 0);
    return sum_a == 0 and sum_b == 0;
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
    std::cout << boolalpha << ans << std::endl;
  }
  return 0;
}
