/**
 * @file 6216.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-23
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdint>
#include <numeric>

#include "common/Vector.hpp"
#include "common/utils.hpp"

using namespace std;

class Solution {
  typedef long long ll;

public:
  long long minCost(vector<int> &nums, vector<int> &cost) {
    int n = nums.size(), i;
    vector<pair<int, int>> a(n);
    for (i = 0; i < n; i++)
      a[i] = make_pair(nums[i], i);
    sort(a.begin(), a.end());
    ll ans = 1LL << 60, s1 = 0, s2 = 0;
    for (i = 0; i < n; i++) {
      s1 -= cost[a[i].second];
      s2 += (ll)a[i].first * cost[a[i].second];
    }
    for (i = 0; i < n; i++) {
      s1 += cost[a[i].second] << 1;
      s2 -= (ll)a[i].first * cost[a[i].second] << 1;
      ans = min(ans, s1 * a[i].first + s2);
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.23/6216.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto cost = string2vector(buf);
    auto ans = sol.minCost(nums, cost);
    std::cout << ans << std::endl;
  }
  return 0;
}
