/**
 * @file 1129.cpp
 * @brief 将每个元素替换为右侧最大元素
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-29
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  vector<int> replaceElements(vector<int> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
      int m = INT_MIN;
      for (size_t j = i + 1; j < arr.size(); ++j) {
        m = max(m, arr[j]);
      }
      if (m == INT_MIN)
        arr[i] = -1;
      else
        arr[i] = m;
    }
    return arr;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  vector<int> arr = {17, 18, 5, 4, 6, 1};
  auto res = ans.replaceElements(arr);
  println_vector(res);
  std::cout << std::endl;
  return 0;
}
