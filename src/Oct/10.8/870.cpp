/**
 * @file 870.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-08
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    int n = static_cast<int>(nums1.size());
    vector<int> ans(n);
    vector<int> mask(n);
    iota(mask.begin(), mask.end(), 0);
    sort(nums1.begin(), nums1.end());
    sort(mask.begin(), mask.end(),
         [&nums2](const int& i, const int& j) { return nums2[i] < nums2[j]; });
    int left = 0, right = n;
    for (int i = 0; i < n; ++i) {
      if (nums1[i] > nums2[mask[left]]) {
        ans[mask[left]] = nums1[i];
        ++left;
      } else {
        ans[mask[right - 1]] = nums1[i];
        right--;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<int> nums1{718967141, 189971378, 341560426, 23521218, 339517772},
      nums2{967482459, 978798455, 744530040, 3454610, 940238504};
  auto ans = sol.advantageCount(nums1, nums2);
  println_vector(ans);
  return 0;
}
