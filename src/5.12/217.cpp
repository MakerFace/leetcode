/**
 * @file 217.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  vector<int> nums{1, 2, 3, 1};
  cout << boolalpha << ans.containsDuplicate(nums) << endl;
  return 0;
}
