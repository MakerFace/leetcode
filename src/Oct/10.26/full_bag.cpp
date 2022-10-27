/**
 * @file full_bag.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-26
 */
#include "common/Vector.hpp"
#include <cstdlib>
#include <fstream>

using namespace std;

class Solution {
public:
  int solve(vector<int> weights, vector<int> values, int k) {
    int m = static_cast<int>(weights.size());
    vector<int> dp(k + 1);
    for (int i = 0; i < m; ++i) {
      for (int j = weights[i]; j <= k; ++j) {
        dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
      }
      std::cout << dp << std::endl;
    }
    return dp[k];
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.26/full_bag.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto weights = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto values = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto k = atoi(buf);
    auto ans = sol.solve(weights, values, k);
    std::cout << ans << std::endl;
  }
  return 0;
}
