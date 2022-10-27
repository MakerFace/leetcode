/**
 * @file 494.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-25
 */
#include "common/Vector.hpp"
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = 0;
    sum = accumulate(nums.begin(), nums.end(), 0);
    if ((target + sum) % 2 == 1 or abs(sum) < target)
      return 0;
    target = (target + sum) / 2;
    if (target < 0)
      return 0;
    int n = static_cast<int>(nums.size());
    vector<int> dp(target + 1);
    dp[0] = 1; // 什么都不装就是一种方式？
    for (int i = 0; i < n; ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] += dp[j - nums[i]]; // 装满背包j有几种方法？
      }
    }
    return dp[target];
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.25/494.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto target = atoi(buf);
    auto ans = sol.findTargetSumWays(nums, target);
    std::cout << ans << std::endl;
  }
  return 0;
}
