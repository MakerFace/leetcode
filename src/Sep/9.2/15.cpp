/**
 * @file 15.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-24
 */
#include "common/Vector.hpp"
#include <algorithm>
#include <fstream>
#include <functional>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    unordered_map<int, vector<pair<int, int>>> map;
    vector<vector<int>> ans;
    int n = static_cast<int>(nums.size());
    sort(nums.begin(), nums.end(), less<int>());
    for (int i = 0; i < n; ++i) { // x
      if (nums[i] > 0)
        break;
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      //   int k = n - 1; TODO why place here?
      //** 主要是因为，nums[j]在增加，所以nums[i]+nums[j]在增大
      //** k只能往前走，找小的！
      for (int j = i + 1; j < n; ++j) { // y
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        int value = -1;
        /* O(N)
        while (k > j) {
          value = nums[i] + nums[j] + nums[k];
          if (value > 0) {
            --k;
          } else {
            break;
          }
        }
        if (not value) {
          ans.push_back({nums[i], nums[j], nums[k]});
        }
        */
        // O(Nlog(N))
        auto z = -(nums[i] + nums[j]);
        if (z < 0) {
          break;
        }
        auto found =
            lower_bound(nums.begin() + j + 1, nums.end(), z) - nums.begin();
        if (found >= 0 and found < n and nums[found] == z) {
          ans.emplace_back(vector<int>{nums[i], nums[j], z});
        }
      }
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Sep/9.2/15.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    auto ans = sol.threeSum(nums);
    std::cout << ans << std::endl;
  }
  return 0;
}
