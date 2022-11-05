/**
 * @file 754.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-04
 */
#include <bits/stdc++.h>
#include <math.h>

#include <cstdlib>

using namespace std;

class Solution {
 public:
  int reachNumber(int target) {
    target = target < 0 ? -target : target;
    int ans = sqrt(double(target) * 2 + 0.25) - 0.5;
    long long sum = long(ans) * long(ans + 1) / 2;
    while (sum < target) {
      ++ans;
      sum += ans;
    }
    while ((sum - target) % 2) {
      ++ans;
      sum += ans;
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.04/754.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto target = atoi(buf);
    auto ans = sol.reachNumber(target);
    std::cout << ans << std::endl;
  }
  return 0;
}
