/**
 * @file 6222.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-30
 */
#include <bits/stdc++.h>

#include <cstdlib>
#include <vector>

#include "common/Vector.hpp"
using namespace std;

class Solution {
 public:
  long long makeIntegerBeautiful(long long n, int target) {
    long long ans = 0;
    vector<int> bits;
    auto temp = n;
    while (n) {
      bits.emplace_back(n % 10);
      n /= 10;
    }
    int sum = 0;
    auto last = bits.crbegin();
    for (; last != bits.crend() and sum < target; last++) {
      sum += *last;
    }
    if (sum == target and last == bits.crend()) {
      return 0;
    }
    if (sum == target) {
      bool zeros = false;
      auto first = last - 1;
      for (; last != bits.crend(); last++) {
        ans *= 10;
        ans += 9 - *last;
        zeros |= *last;
      }
      if (not zeros) {
        return 0;
      }
      int bits_count = bits.crend() - first - 1;
      temp = (9 - *first) * pow(10, bits_count);
      return temp + ans + 1;
    } else if (sum > target) {
      for (--last; last != bits.crend(); last++) {
        ans *= 10;
        ans += 9 - *last;
      }
      return ans + 1;
    }
    return 0;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.30/6222.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoll(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto target = atoi(buf);
    auto ans = sol.makeIntegerBeautiful(n, target);
    std::cout << ans << std::endl;
  }
  return 0;
}
