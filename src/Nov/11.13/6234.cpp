/**
 * @file 6234.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-13
 */
#include <bits/stdc++.h>

#include <cstdlib>
#include <unordered_set>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int subarrayLCM(vector<int>& nums, int k) {
    const int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int l = 1;
      for (int j = i; j < n; ++j) {
        l = lcm(l, nums[j]);
        if (l == k) {
          ans++;
        }
      }
    }
    return ans;
  }

 private:
  long gcd(long a, long b) { return (a % b == 0) ? b : gcd(b, a % b); }

  long lcm(long a, long b) { return a / gcd(a, b) * b; }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.13/6234.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto k = atoi(buf);
    auto ans = sol.subarrayLCM(nums, k);
    std::cout << ans << std::endl;
  }
  return 0;
}
