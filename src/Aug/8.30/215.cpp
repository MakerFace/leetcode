/**
 * @file 215.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-08-30
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 快速选择（快排改版）O(n)。
 */
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    tail = nums.end();
    return quick_select(nums.begin(), nums.end(), k);
  }

 private:
  vector<int>::iterator tail;

 private:
  int quick_select(vector<int>::iterator begin, vector<int>::iterator end,
                   int k) {
    if (begin == end) {
      return -1;
    }
    auto it = begin;
    auto save = begin;
    swap(*save, *(end - 1));  ///* 交换基准begin和区间尾end
    while (it < end) {        ///* it扫描全表
      if (*it <
          *(end - 1)) {  ///* 如果it小于基准，则交换it和begin，同时向后移动
        swap(*save, *it);
        ++save;
      }
      // else // 否则begin保持不动，直到出现下一个小的，或者结束扫描
      ++it;
    }
    swap(*save, *(end - 1));
    if (tail - save == k) {
      return *save;
    } else if (tail - save < k) {
      return quick_select(begin, save, k);
    } else {
      return quick_select(save + 1, end, k);
    }
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<int> nums({3, 1,  2, 3,  54, 5, 6, 7, 87, 8, 5, 21, 4,
                    3, 2,  2, 2,  3,  4, 5, 6, 76, 7, 8, 8,  98,
                    9, 65, 4, 34, 32, 3, 3, 4, 5,  6, 7, 87, 23});
  int k = 5;
  cout << sol.findKthLargest(nums, k) << endl;
  return 0;
}
