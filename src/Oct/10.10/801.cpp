/**
 * @file 801.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-10
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  int minSwap(vector<int>& nums1, vector<int>& nums2) {
    int a = 0, b = 1;
    int n = static_cast<int>(nums1.size());
    for (size_t i = 1; i < nums1.size(); ++i) {
      int at = a, bt = b;
      a = n, b = n;
      if (nums1[i] > nums1[i - 1] and nums2[i] > nums2[i - 1]) {
        a = min(a, at);
        b = min(b, bt + 1);
      }
      if (nums2[i] > nums1[i - 1] and nums1[i] > nums2[i - 1]) {
        a = min(a, bt);
        b = min(b, at + 1);
      }
    }
    return min(a, b);
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  string s = string(PROJECT_PATH).append("/src/Oct/10.10/801.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    vector<int> nums1, nums2;
    s = buf;
    nums1 = string2vector(s);
    in.getline(buf, MAX_LINE_SIZE);
    s = buf;
    nums2 = string2vector(s);
    auto ans = sol.minSwap(nums1, nums2);
    std::cout << ans << std::endl;
  }
  return 0;
}
