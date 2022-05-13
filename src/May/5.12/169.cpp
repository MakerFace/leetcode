/**
 * @file 169.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Boyer-Moore投票法
 * count == 0则将候选数记为当前数
 * 候选数与当前数相等，count+1
 * 否则count-1
 * 如果一定存在众数，那么遍历一遍之后
 * 候选数就是众数。
 */
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate;
    for (int i = 0; i < nums.size(); ++i) {
      if (not count) candidate = nums[i];
      if (candidate == nums[i])
        ++count;
      else
        --count;
    }
    return candidate;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  vector<int> nums{2, 2, 1, 1, 1, 2, 2};
  std::cout << ans.majorityElement(nums) << std::endl;
  return 0;
}
