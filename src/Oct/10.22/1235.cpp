/**
 * @file 1235.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-22
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>

#include "common/Vector.hpp"
#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    int n = startTime.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&](int i, int j) -> bool { return endTime[i] < endTime[j]; });
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
      int k =
          upper_bound(idx.begin(), idx.begin() + i - 1, startTime[idx[i - 1]],
                      [&](int st, int j) -> bool { return st < endTime[j]; }) -
          idx.begin();
      dp[i] = max(dp[i - 1], dp[k] + profit[idx[i - 1]]);
    }
    return dp[n];
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.22/1235.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto startTime = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto endTime = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto profit = string2vector(buf);
    auto ans = sol.jobScheduling(startTime, endTime, profit);
    std::cout << ans << std::endl;
  }
  return 0;
}
