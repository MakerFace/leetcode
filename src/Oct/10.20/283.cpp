/**
 * @file 283.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-20
 */
#include <bits/stdc++.h>

#include "common/Vector.hpp"
#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int left = 0;
    int n = static_cast<int>(nums.size());
    int length = 0;
    while (left < n) {
      while (left < n and nums[left] == 0) {
        ++left;
      }
      if (left >= n)
        break;
      nums[length++] = nums[left++];
    }
    for (int i = length; i < n; ++i) {
      nums[i] = 0;
    }
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.20/283.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto nums = string2vector(s);
    sol.moveZeroes(nums);
    std::cout << nums << std::endl;
  }
  return 0;
}
