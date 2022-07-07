/**
 * @file 961.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-21
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int repeatedNTimes(vector<int>& nums) {
    // int n = nums.size() / 2;
    unordered_set<int> set;
    for (auto var : nums) {
      if (set.count(var)) return var;
      set.insert(var);
    }
    //     unordered_map<int, int> map;
    //     for (auto var : nums) {
    //       map[var]++;
    //       if (map[var] == n) {
    //         return var;
    //       }
    //     }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  vector<int> nums{5, 1, 5, 2, 5, 3, 5, 4};
  std::cout << ans.repeatedNTimes(nums) << std::endl;
  return 0;
}
