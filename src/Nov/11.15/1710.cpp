/**
 * @file 1710.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-15
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "common/Matrix.hpp"
using namespace std;

class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    int ans = 0;
    sort(boxTypes.begin(), boxTypes.end(),
         [](vector<int>& a, vector<int>& b) { return a[1] > b[1]; });
    int count = 0;
    for (auto&& b : boxTypes) {
      if (b[0] + count <= truckSize) {
        ans += b[0] * b[1];
        count += b[0];
      } else {
        ans += (truckSize - count) * b[1];
        break;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.15/1710.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto boxTypes = string2matrix(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto truckSize = atoi(buf);
    auto ans = sol.maximumUnits(boxTypes, truckSize);
    std::cout << ans << std::endl;
  }
  return 0;
}
