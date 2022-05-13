/**
 * @file 45.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-07
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int jump(vector<int> &nums) {
    int result = 0;
    size_t max_len = 0;
    size_t end = 0;  // 相比于55题，多了一个边界，到达边界则跳一次
    size_t i;
    for (i = 0; i < nums.size() - 1; ++i) {
      if (max_len >= i) {
        max_len = max(max_len, i + nums[i]);
        if (i == end) {
          end = max_len;
          ++result;
        }
      }
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  vector<int> nums = {2, 3, 1, 1, 4};
  std::cout << ans.jump(nums) << std::endl;
  return 0;
}
