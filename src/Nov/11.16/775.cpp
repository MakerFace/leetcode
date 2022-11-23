/**
 * @file 775.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-16
 */
#include <bits/stdc++.h>

#include <ios>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  bool isIdealPermutation(vector<int>& nums) {
    const int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      if (abs(nums[i] - i) > 1) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.16/775.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    auto ans = sol.isIdealPermutation(nums);
    std::cout << boolalpha << ans << std::endl;
  }
  return 0;
}
