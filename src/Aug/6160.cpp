/**
 * @file 6160.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-08-28
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    vector<int> ans(queries.size());
    for (size_t i = 0; i < queries.size(); ++i) {
      size_t len = 0;
      int temp = 0;
      for (; len < nums.size(); ++len) {
        temp += nums[len];
        if (temp > queries[i]) {
          break;
        }
      }
      ans[i] = len;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums({4, 5, 2, 1});
  vector<int> queries({3, 10, 21});
  auto ans = s.answerQueries(nums, queries);
  print_vector(ans);
  return 0;
}
