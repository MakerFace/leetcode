/**
 * @file 6200.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-09
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int hardestWorker(int n, vector<vector<int>>& logs) {
    sort(
        logs.begin(), logs.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
    size_t idx = logs[0][0];
    int count = logs[0][1];
    for (size_t i = 1; i < logs.size(); ++i) {
      auto temp = logs[i][1] - logs[i - 1][1];
      if (count < temp) {
        count = temp;
        idx = logs[i][0];
      } else if (count == temp) {
        idx = min(idx, static_cast<size_t>(logs[i][0]));
      }
    }
    return static_cast<int>(idx);
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<vector<int>> logs{{36, 3},  {1, 5},   {12, 8}, {25, 9},
                           {53, 11}, {29, 12}, {52, 14}};
  std::cout << sol.hardestWorker(70, logs) << std::endl;
  return 0;
}
