/**
 * @file 915.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-24
 */
#include "common/Vector.hpp"
#include <algorithm>
#include <array>
#include <fstream>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
public:
  int partitionDisjoint(vector<int> &nums) {
    int n = static_cast<int>(nums.size());
    int left = 0, right = n - 1;
    int left_max = nums[left];
    while (true) {
      while (right > left and left_max > nums[right--])
        ;
      if (right <= left)
        break;
      int new_max = left_max;
      for (int i = left; i < right; ++i) {
        new_max = max(left_max, nums[i]);
      }
      if (new_max == left_max) {
        break;
      }
      left_max = new_max;
    }
    return right;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.24/915.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    auto ans = sol.partitionDisjoint(nums);
    std::cout << ans << std::endl;
  }
  return 0;
}
