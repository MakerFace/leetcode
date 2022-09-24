/**
 * @file 1636.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-19
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> map;
    for (auto& n : nums) {
      map[n]++;
    }
    sort(nums.begin(), nums.end(), [&](const int& a, const int& b) {
      if (map[a] == map[b]) return a < b;
      if (map[a] < map[b]) return true;
      return false;
    });
    return nums;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<int> nums{1, 1, 2, 2, 2, 3};
  println_vector(sol.frequencySort(nums));
  return 0;
}
