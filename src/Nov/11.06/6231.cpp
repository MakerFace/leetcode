/**
 * @file 6231.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-06
 */
#include <bits/stdc++.h>

#include <cstdlib>
#include <functional>
#include <numeric>
#include <queue>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    priority_queue<int, vector<int>, greater<int>> front, back;
    const int n = costs.size();
    int ftop = 0, btop = n - 1;
    for (int i = 0; i < candidates and ftop <= btop; ++i) {
      front.emplace(costs[ftop++]);
      if (ftop > btop) {
        break;
      }
      back.emplace(costs[btop--]);
    }
    long long ans = 0;
    while (k) {
      if (not front.empty() and not back.empty()) {
        if (front.top() <= back.top()) {
          ans += front.top();
          front.pop();
          if (ftop <= btop) {
            front.emplace(costs[ftop++]);
          }
        } else {
          ans += back.top();
          back.pop();
          if (ftop <= btop) {
            back.emplace(costs[btop--]);
          }
        }
      } else if (not front.empty()) {
        ans += front.top();
        front.pop();
      } else if (not back.empty()) {
        ans += back.top();
        back.pop();
      }
      --k;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.06/6231.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto costs = string2vector(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto k = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto candidates = atoi(buf);
    auto ans = sol.totalCost(costs, k, candidates);
    std::cout << ans << std::endl;
  }
  return 0;
}
