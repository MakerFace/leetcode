/**
 * @file 6188.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-25
 */

#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  vector<int> goodIndices(vector<int>& nums, int k) {
    vector<int> ans;
    if (k == 1) {
      ans.resize(nums.size() - 2);
      iota(ans.begin(), ans.end(), 1);
      return ans;
    }
    int n = static_cast<int>(nums.size());
    int f_l = 0, f_r = k - 1;
    int b_l = k + 1, b_r = k + k;
    while (b_r < n) {
      int i = f_l;
      int j = b_l;
      for (; i <= f_r; ++i, ++j) {
        if (i == f_r) break;
        if (nums[i + 1] > nums[i]) break;
        if (nums[j + 1] < nums[j]) break;
      }
      if (i != f_r or j != b_r) {
        f_l = i + 1;
        f_r = f_l + k - 1;
        b_l = j + 1;
        b_r = b_l + k - 1;
        continue;
      }
      while (b_r < n) {
        if (nums[f_r] <= nums[f_r - 1] and nums[b_r] >= nums[b_r - 1]) {
          ans.push_back(f_r + 1);
        } else {
          break;
        }
        f_l++;
        f_r++;
        b_l++;
        b_r++;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<int> nums{
      123592,  303692,  752301,  522418,  100,     68,      12,      12,
      11,      7,       3,       2,       1,       1,       1,       1,
      1,       1,       1,       477952,  882691,  945349,  997202,  999245,
      999319,  999911,  999913,  999985,  999996,  999996,  999996,  1000000,
      1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000,
      1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000,
      1000000, 1000000, 1000000, 1000000, 482896,  250330,  20230,   570399,
      972746,  999408};
  auto ans = sol.goodIndices(nums, 12);
  println_vector(ans);
  return 0;
}
