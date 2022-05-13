/**
 * @file 1.cpp
 * @brief 两数之和
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-02-28
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 还是得用哈希表做，unordered map是key无序哈希表，查找效率是O(1)
 * map和multimap是有序的，底层实现是红黑树，查找效率是O(log(n))
 */
class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res;
    unordered_map<int, int> map;
    for (size_t i = 0; i < nums.size(); i++) {
      auto iter = map.find(target - nums[i]);
      if (iter != map.end()) {
        return {iter->second, (int)i};
      }
      map.insert(pair<int, int>(nums[i], i));
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> nums = {2, 11, 7, 15};
  auto res = s.twoSum(nums, 17);
  for (size_t i = 0; i < res.size(); i++) {
    std::cout << res[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}
