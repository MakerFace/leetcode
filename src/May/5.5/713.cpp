/**
 * @file 713.cpp
 * @brief 乘积小于 K 的子数组
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-05
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int result = 0;
    int prod = 1;
    size_t i = 0;
    for (size_t j = 0; j < nums.size(); ++j) {
      prod *= nums[j];
      while (i <= j && prod >= k) {
        prod /= nums[i];
        ++i;
      }
      result += j - i + 1;
    }
    return result;
  }
};
int main(int argc, char const *argv[]) {
  Solution ans;
  vector<int> nums = {10, 5, 2, 6};
  int k = 100;
  while (cin >> k) {
    auto res = ans.numSubarrayProductLessThanK(nums, k);
    std::cout << res << std::endl;
  }
  return 0;
}
