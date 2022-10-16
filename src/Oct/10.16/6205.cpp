/**
 * @file 6205.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-16
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  int countDistinctIntegers(vector<int>& nums) {
    unordered_set<int> set;
    for (auto n : nums) {
      set.insert(n);
      set.insert(reverse(n));
    }
    return set.size();
  }

 private:
  int reverse(int n) {
    int temp = 0;
    while (n) {
      temp *= 10;
      temp += n % 10;
      n /= 10;
    }
    return temp;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.15/6205.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto nums = string2vector(s);
    auto ans = sol.countDistinctIntegers(nums);
    std::cout << ans << std::endl;
  }
  return 0;
}
