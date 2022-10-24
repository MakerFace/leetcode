/**
 * @file 6215.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-23
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
#include <unordered_map>
#include <vector>

#include "common/Vector.hpp"
#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  int subarrayGCD(vector<int> &nums, int k) {
    int ans = 0;
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
      int max_gcd = nums[i];
      if (max_gcd == k) {
        ans++;
      }
      for (int j = i + 1; j < n; ++j) {
        max_gcd = min(max_gcd, gcd(max_gcd, nums[j]));
        if (max_gcd == k) {
          ans++;
        } else if (max_gcd < k) {
          break;
        }
      }
    }
    return ans;
  }

private:
  int gcd(int a, int b) {
    if (a == 0)
      return b;
    if (b == 0)
      return a;
    if (a % 2 == 0 && b % 2 == 0)
      return 2 * gcd(a >> 1, b >> 1);
    else if (a % 2 == 0)
      return gcd(a >> 1, b);
    else if (b % 2 == 0)
      return gcd(a, b >> 1);
    else
      return gcd(abs(a - b), min(a, b));
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.23/6215.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto k = atoi(buf);
    auto ans = sol.subarrayGCD(nums, k);
    std::cout << ans << std::endl;
  }
  return 0;
}
