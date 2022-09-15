/**
 * @file 670.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-13
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maximumSwap(int num) {
    vector<int> nums;
    while (num) {
      nums.push_back(num % 10);
      num /= 10;
    }
    int length = nums.size();
    int i = length - 1;
    for (; i > 0; i--) {  // i之前递增
      if (nums[i - 1] > nums[i]) break;
    }
    int j = i - 1;
    int idx = j;
    int max = 0;
    for (; j >= 0; j--) {
      if (max <= nums[j]) {
        max = nums[j];
        idx = j;
      }
    }
    while (i < length and nums[i] < max) {
      ++i;
    }
    --i;
    if (max > 0) swap(nums[i], nums[idx]);
    int ans = 0;
    for (int i = length - 1; i >= 0; i--) {
      ans *= 10;
      ans += nums[i];
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  int num;
  while (cin >> num) {
    std::cout << sol.maximumSwap(num) << std::endl;
  }
  return 0;
}
