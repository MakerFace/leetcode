/**
 * @file 1619.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-14
 */

#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  double trimMean(vector<int>& arr) {
    int n = arr.size() * 0.05;
    sort(arr.begin(), arr.end());
    
    double sum = 0.0;
    for (size_t i = n; i < arr.size() - n; i++) {
      sum += arr[i];
    }
    return sum / (arr.size() - 2 * n);
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<int> arr{4,  8, 4, 10, 0,  7,  1, 3, 7,  8,  8, 3,  4, 1,  6, 2,
                  1,  1, 8, 0,  9,  8,  0, 3, 9,  10, 3, 10, 1, 10, 7, 3,
                  2,  1, 4, 9,  10, 7,  6, 4, 0,  8,  5, 1,  2, 1,  6, 2,
                  5,  0, 7, 10, 9,  10, 3, 7, 10, 5,  8, 5,  7, 6,  7, 6,
                  10, 9, 5, 10, 5,  5,  7, 2, 10, 7,  7, 8,  2, 0,  1, 1};
  std::cout << sol.trimMean(arr) << std::endl;
  return 0;
}
