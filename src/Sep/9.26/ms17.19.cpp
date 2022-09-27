/**
 * @file ms17.19.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-26
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  vector<int> missingTwo(vector<int> &nums) {
    long long n = static_cast<int>(nums.size()) + 2;
    long long qua_n = n * (2 * n + 1) * (n + 1) / 6;
    long long sum_n = n * (n + 1) / 2;
    long long qua_res = 0;
    long long sum_res = 0;
    for_each(nums.begin(), nums.end(), [&](const int &n) {
      sum_res += n;
      qua_res += n * n;
    });
    qua_res = qua_n - qua_res;
    sum_res = sum_n - sum_res;                  // (a+b)
    qua_n = (sum_res * sum_res - qua_res) / 2;  // ab=((a+b)^2-(a^2+b^2))/2
    qua_n = ceil(sqrt(sum_res * sum_res / 4 - qua_n) +
                  sum_res / 2);  // a = √(n^2/4-m)+n/2
    sum_n = sum_res - qua_n;     // b = n - a
    return vector<int>{static_cast<int>(qua_n), static_cast<int>(sum_n)};
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  vector<int> nums(2998);
  iota(nums.begin(), nums.begin() + 4, 1);
  iota(nums.begin() + 4, nums.begin() + 6, 6);
  iota(nums.begin() + 6, nums.end(), 9);
  random_shuffle(nums.begin(), nums.end());
  auto ans = sol.missingTwo(nums);
  println_vector(ans);
  return 0;
}
