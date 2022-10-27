/**
 * @file 416.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-24
 */
#include "common/Vector.hpp"
#include <fstream>
#include <ios>
#include <vector>

using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int target = 0;
    int n = static_cast<int>(nums.size());
    for (auto n : nums) {
      target += n;
    }
    if (target % 2 == 1) {
      return false;
    }
    target /= 2;
    vector<int> dp(target + 1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      //   for (int j = 1; j <= target and j >= nums[i]; ++j) {
      for (int j = target; j >= nums[i] and j >= 1; --j) {
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }
    return dp[target] == target;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.24/416.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    auto ans = sol.canPartition(nums);
    std::cout << boolalpha << ans << std::endl;
  }
  return 0;
}
