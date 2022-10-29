/**
 * @file 6226.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-29
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <cstddef>
#include <functional>
#include <utility>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int destroyTargets(vector<int>& nums, int space) {
    int n = static_cast<int>(nums.size());
    sort(nums.begin(), nums.end(), greater<int>());
    vector<int> counter(space + 1);
    int max = 0;
    int ans = 0;
    for (auto t : nums) {
      ++counter[t % space];
      if (counter[t % space] >= max) {
        max = counter[t % space];
        ans = t;
      }
    }
    return ans;
  }

//  public:
//   vector<int> vals;
//   int get(int x) {
//     return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
//   }
//   int destroyTargets(vector<int>& nums, int space) {
//     for (auto t : nums) vals.push_back(t % space);
//     sort(vals.begin(), vals.end());
//     vals.erase(unique(vals.begin(), vals.end()), vals.end());
//     sort(nums.begin(), nums.end(), greater<int>());
//     vector<int> counter(vals.size());
//     int max = 0;
//     int ans = 0;
//     for (auto t : nums) {
//       ++counter[get(t % space)];
//       if (counter[get(t % space)] >= max) {
//         max = counter[get(t % space)];
//         ans = t;
//       }
//     }
//     return ans;
//   }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.29/6226.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto space = atoi(buf);
    auto ans = sol.destroyTargets(nums, space);
    std::cout << ans << std::endl;
  }
  return 0;
}
