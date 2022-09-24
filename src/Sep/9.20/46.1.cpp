/**
 * @file premutation.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-20
 */

#include <vector>

#include "common/Matrix.hpp"
using namespace std;

template <typename T>
T compute(T x) {
  if (x <= 1) return 1;
  return compute(x - 1) * x;
}

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    len = static_cast<int>(nums.size());
    ans.reserve(compute(len));
    permutation(nums, 0);
    return ans;
  }

 private:
  void permutation(vector<int>& nums, int idx) {
    if (idx == len) {
      ans.emplace_back(nums);
      return;
    }
    for (int i = idx; i < len; i++) {
      swap(nums[idx], nums[i]);  // 交换idx,i
      permutation(nums, idx + 1);
      swap(nums[idx], nums[i]);  // 还原
    }
  }

 private:
  int len;
  vector<vector<int>> ans;
};

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 2, 3, 4};
  Solution sol;
  auto ans = sol.permute(nums);
  println_matrix(ans);
  return 0;
}
