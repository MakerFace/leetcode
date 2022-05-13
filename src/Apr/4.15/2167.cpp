/**
 * @file 2167.cpp
 * @brief 移除所有载有违禁货物车厢所需要的最少时间
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-15
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumTime(string s) {
    int res = INT_MAX;
    int prebest = 0;
    int presum = 0;
    for (size_t j = 0; j < s.size(); ++j) {
      prebest = min(prebest, (int)j - 2 * presum);
      presum += s[j] - '0';
      res = min(res, prebest + 2 * presum - (int)j);
    }
    return min(res + s.size() - 1, s.size());
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::cout << s.minimumTime("011101011110") << std::endl;
  return 0;
}
