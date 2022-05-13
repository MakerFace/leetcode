/**
 * @file 1619.cpp
 * @brief 删除某些元素后的数组均值
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-29
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  double trimMean(vector<int> &arr) {
    int len = arr.size() * 0.05;
    sort(arr.begin(), arr.end());
    int result = 0;
    for (size_t i = len; i < arr.size() - len; ++i) {
      result += arr[i];
    }
    return (double(result)) / (arr.size() - 2 * len);
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  vector<int> arr = {6,  0, 7, 0, 7, 5, 7, 8,  3, 4, 0, 7, 8, 1,
                     6,  8, 1, 1, 2, 4, 8, 1,  9, 5, 4, 3, 8, 5,
                     10, 8, 6, 6, 1, 0, 6, 10, 8, 2, 3, 4};
  std::cout << ans.trimMean(arr) << std::endl;
  return 0;
}
