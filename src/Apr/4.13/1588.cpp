/**
 * @file 1588.cpp
 * @brief 所有奇数长度子数组的和
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-13
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int sumOddLengthSubarrays(vector<int> &arr) {
    int sum = 0;
    size_t size = 1;
    while (size <= arr.size()) {
      for (size_t i = 0; i <= arr.size() - size; i++) {
        for (size_t j = 0; j < size; j++) {
          sum += arr[i + j];
        }
      }
      size += 2;
    }
    return sum;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> arr = {10, 11, 12};
  auto res = s.sumOddLengthSubarrays(arr);
  std::cout << res << std::endl;
  return 0;
}
