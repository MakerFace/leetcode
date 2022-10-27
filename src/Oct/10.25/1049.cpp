/**
 * @file 1049.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-24
 */
#include <bits/stdc++.h>
#include <fstream>
#include <numeric>
#include <vector>

#include "common/ListNode.hpp"
#include "common/Vector.hpp"

using namespace std;

class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int ans = 0, sum = 0, target;
    vector<int> dp;
    sum = accumulate(stones.begin(), stones.end(), 0);
    target = sum / 2;
    dp.resize(target + 1);
    for (auto s : stones) {
      for (int j = target; j >= 1 and j >= s; --j) {
        dp[j] = max(dp[j], dp[j - s] + s);
      }
    }
    return sum - dp[target] * 2;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.25/1049.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto stones = string2vector(buf);
    auto ans = sol.lastStoneWeightII(stones);
    std::cout << ans << std::endl;
  }
  return 0;
}
