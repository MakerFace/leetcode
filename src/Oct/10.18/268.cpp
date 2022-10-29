/**
 * @file 268.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-18
 */
#include <bits/stdc++.h>

#include "common/Vector.hpp"
#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = static_cast<int>(nums.size()) + 1;
    int sum = 0;
    for (auto &n : nums) {
      sum += n;
    }
    return n * (n - 1) / 2 - sum;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.18/268.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto nums = string2vector(s);
    auto ans = sol.missingNumber(nums);
    std::cout << ans << std::endl;
  }
  return 0;
}
