/**
 * @file 414.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-19
 */
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <unordered_set>

#include "common/Vector.hpp"
#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  int thirdMax(vector<int> &nums) {
    unordered_set<int> set;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &n : nums) {
      if (set.count(n) == 0) {
        set.insert(n);
        pq.emplace(n);
        if (pq.size() > 3) {
          pq.pop();
        }
      }
    }
    if (pq.size() == 3) {
      return pq.top();
    }
    int ans = 0;
    while (not pq.empty()) {
      ans = max(ans, pq.top());
      pq.pop();
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.19/414.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto nums = string2vector(s);
    auto ans = sol.thirdMax(nums);
    std::cout << ans << std::endl;
  }
  return 0;
}
