/**
 * @file 6237.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-12
 */
#include <bits/stdc++.h>

#include "common/Vector.hpp"
using namespace std;

class Solution {
 public:
  int distinctAverages(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    unordered_set<double> set;
    int i = 0, j = nums.size() - 1;
    while (i < j) {
      set.insert((nums[i] + nums[j]) / 2.0);
      ++i, --j;
    }
    return set.size();
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.12/6237.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    auto ans = sol.distinctAverages(nums);
    std::cout << ans << std::endl;
  }
  return 0;
}
