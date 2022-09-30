/**
 * @file 1608.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-12
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int x = 0;
    int i = 0;
    int n = nums.size();
    for (; x <= n; x++) {
      while (i < n and nums[i] < x) {
        ++i;
      }
      if (n - i == x) {
        return x;
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<int> nums{3, 6, 7, 7, 0};
  std::cout << sol.specialArray(nums) << std::endl;
  return 0;
}
