/**
 * @file 698.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-20
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    auto sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k) {
      return false;
    }

    this->k = k;
    target = sum / k;
    sort(nums.begin(), nums.end(), greater<int>());
    len = static_cast<int>(nums.size());
    if (nums[len - 1] > target) return false;  // 最大值超过均值则不可能划分
    cur_sum.resize(k);
    function<bool(int)> dfs;
    dfs = [&](int i) {
      if (i == len) {
        return true;
      }
      for (int j = 0; j < k; ++j) {
        if (j && cur_sum[j] == cur_sum[j - 1]) {
          continue;
        }
        cur_sum[j] += nums[i];
        if (cur_sum[j] <= target && dfs(i + 1)) {
          return true;
        }
        cur_sum[j] -= nums[i];
      }
      return false;
    };
    return dfs(0);
  }

 private:
  vector<int> cur_sum;
  int k, target, len;
};

int main(int argc, char const* argv[]) {
  vector<int> nums{2, 2, 2, 2, 3, 4, 5};
  int k = 4;
  Solution sol;
  std::cout << boolalpha << sol.canPartitionKSubsets(nums, k) << std::endl;
  return 0;
}
