/**
 * @file 6230.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-06
 */
#include <bits/stdc++.h>

#include <cstdlib>
#include <unordered_set>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_set<int> set;
    long long ans = 0;
    int i = 0;
    int j = 0;
    long long sum = 0;
    while (j < nums.size()) {
      while (set.size() < k and j < nums.size()) {
        auto res = set.insert(nums[j]);
        while (not res.second) {
          set.erase(nums[i]);
          sum -= nums[i];
          res = set.insert(nums[j]);
          ++i;
        }
        sum += nums[j];
        ++j;
      }
      if (set.size() == k) {
        ans = max(ans, sum);
        sum -= nums[i];
        set.erase(nums[i]);
        ++i;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.06/6230.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto k = atoi(buf);
    auto ans = sol.maximumSubarraySum(nums, k);
    std::cout << ans << std::endl;
  }
  return 0;
}
