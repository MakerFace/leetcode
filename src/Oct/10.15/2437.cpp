/**
 * @file test1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-15
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  int countTime(string time) {
    int hour = count(time.substr(0, 2), "23");
    int min = count(time.substr(3, 2), "59");
    return hour * min;
  }

 private:
  int count(string num, string limit) {
    if (num == "??") {
      return atoi(limit.c_str()) + 1;
    }
    if (num[0] == '?') {
      num[0] = '0';
      int i;
      for (i = 0; i < 10 and num <= limit; i++) {
        num[0]++;
      }
      return i;
    } else if (num[1] == '?') {
      num[1] = '0';
      int i;
      for (i = 0; i < 10 and num <= limit; i++) {
        num[1]++;
      }
      return i;
    } else {
      return 1;
    }
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.15/test1.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto ans = sol.countTime(s);
    std::cout << ans << std::endl;
  }
  return 0;
}
