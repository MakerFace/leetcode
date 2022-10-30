/**
 * @file 198.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-29
 */
#include <fstream>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= n; ++i) {
      dp[i] += max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[n];
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.29/198.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    auto ans = sol.rob(nums);
    std::cout << ans << std::endl;
  }
  return 0;
}
