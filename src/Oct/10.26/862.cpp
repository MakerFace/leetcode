/**
 * @file 862.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-26
 */
#include "common/Vector.hpp"
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <queue>

using namespace std;

class Solution {
public:
  int shortestSubarray(vector<int> &nums, int k) {
    int n = static_cast<int>(nums.size());
    int ans = n + 1;
    vector<long> pre_sum(n + 1);
    deque<int> deq;
    for (int i = 0; i < n; ++i) {
      pre_sum[i + 1] = pre_sum[i] + nums[i];
    }
    for (int i = 0; i <= n; ++i) {
      long cur_sum = pre_sum[i];
      while (not deq.empty() and cur_sum - pre_sum[deq.front()] >= k) {
        ans = min(ans, i - deq.front());
        deq.pop_front();
      }
      while (not deq.empty() and pre_sum[deq.back()] >= cur_sum) {
        deq.pop_back();
      }
      deq.emplace_back(i);
    }
    return ans < n + 1 ? ans : -1;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.26/862.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto k = atoi(buf);
    auto ans = sol.shortestSubarray(nums, k);
    std::cout << ans << std::endl;
  }
  return 0;
}
