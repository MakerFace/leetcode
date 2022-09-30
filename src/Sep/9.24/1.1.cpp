/**
 * @file 1.1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-24
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
    int n = static_cast<int>(temperatureA.size());
    int ans = 0, count = 0;
    for (int i = 1; i < n; ++i) {
      auto change_a = temperatureA[i] - temperatureA[i - 1];
      auto change_b = temperatureB[i] - temperatureB[i - 1];
      if ((change_a * change_b > 0) or (change_a == 0 and change_b == 0))
        ++count;
      else
        count = 0;
      ans = max(ans, count);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> ta{5,10,16,-6,15,11,3}, tb{16,22,23,23,25,3,-16};
  Solution sol;
  cout << sol.temperatureTrend(ta, tb) << endl;
  return 0;
}
