/**
 * @file 80.cpp
 * @brief 删除有序数组中的重复项II
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-26
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    size_t first = 0;
    size_t pre = 0;
    size_t cur = 0;
    size_t count = 0;
    while (first < nums.size()) {
      if (nums[first] != nums[pre]) {
        count = 0;
        pre = first;
      }
      ++count;
      if (count <= 2) {
        nums[cur++] = nums[first];
      }
      ++first;
    }
    return (int)cur;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  int n;
  while (cin >> n) {
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
      cin >> nums[i];
    }
    auto res = ans.removeDuplicates(nums);
    std::cout << nums[0];
    for (int i = 1; i < res; ++i) {
      std::cout << "," << nums[i];
    }
    std::cout << std::endl;
  }
  return 0;
}
