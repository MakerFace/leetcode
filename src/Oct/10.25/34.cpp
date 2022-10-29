/**
 * @file 34.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-25
 */
#include "common/Vector.hpp"
#include <algorithm>
#include <cstdlib>
#include <fstream>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.empty()) {
      return vector<int>{-1, -1};
    }
    auto left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (left < 0 or left >= static_cast<int>(nums.size()) or nums[left] != target) {
      return vector<int>{-1, -1};
    }
    auto right =
        upper_bound(nums.begin() + left, nums.end(), target) - nums.begin();
    return vector<int>{static_cast<int>(left), static_cast<int>(right - 1)};
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.25/34.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto target = atoi(buf);
    auto ans = sol.searchRange(nums, target);
    std::cout << ans << std::endl;
  }
  return 0;
}
