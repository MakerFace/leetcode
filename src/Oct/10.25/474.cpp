/**
 * @file 474.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-25
 */
#include "common/Vector.hpp"
#include <cstdlib>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    int s = static_cast<int>(strs.size());
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 0;
    for (auto str : strs) {
      int zeros = 0, ones = 0;
      for (auto c : str) {
        zeros += c == '0';
        ones += c == '1';
      }
      for (int i = m; i >= zeros; --i) {
        for (int j = n; j >= ones; --j) {
          dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }
      }
    }
    return dp[m][n];
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.25/474.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto strs = string2vector<string>(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto m = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto n = atoi(buf);
    auto ans = sol.findMaxForm(strs, m, n);
    std::cout << ans << std::endl;
  }
  return 0;
}
