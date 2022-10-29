/**
 * @file 377.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-26
 */
#include "common/Vector.hpp"
#include <cstdint>
#include <cstdlib>
#include <fstream>

using namespace std;

class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int j = 1; j <= target; ++j) {
      for (auto n : nums) {
        if (j < n or dp[j] >= INT32_MAX - dp[j - n])
          continue;
        dp[j] += dp[j - n];
      }
    }
    return dp[target];
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.26/377.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto target = atoi(buf);
    auto ans = sol.combinationSum4(nums, target);
    std::cout << ans << std::endl;
  }
  return 0;
}
