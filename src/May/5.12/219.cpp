/**
 * @file 219.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (size_t i = 0; i < nums.size(); ++i) {
      auto iter = map.find(nums[i]);
      if (iter == map.end()) {
        map.insert(make_pair(nums[i], i));
      } else if ((int)i - iter->second <= k) {
        return true;
      } else {
        iter->second = i;
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 2, 3, 1, 2, 3};
  Solution ans;
  int k;
  while (cin >> k) {
    std::cout << boolalpha << ans.containsNearbyDuplicate(nums, k) << std::endl;
  }
  return 0;
}
