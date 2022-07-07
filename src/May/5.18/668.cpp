/**
 * @file 668.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-18
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  int findKthNumber(int m, int n, int k) {
    int start = 1, end = m * n;
    while (start < end) {
      int mid = start +
                (end - start) / 2;  // end-start是指区间长度，start表示区间起点
      // 当x<floor(mid/n)时，floor(mid/i)>=n，然后一行最多n个，因此前floor(mid/n)行都是n个数
      int count = mid / n * n;
      for (int x = mid / n + 1; x <= m; ++x) {
        count += mid / x;
      }
      if (count >= k)
        end = mid;
      else
        start = mid + 1;
    }
    return start;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  int m, n, k;
  while (cin >> m >> n >> k) {
    std::cout << ans.findKthNumber(m, n, k) << std::endl;
  }
  return 0;
}
