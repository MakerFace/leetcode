/**
 * @file 1742.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-23
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <cstdlib>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int countBalls(int lowLimit, int highLimit) {
    int result = 0;
    array<int, 46> resultMap{0};
    for (int i = lowLimit; i <= highLimit; i++) {
      int num = i, index = 0;
      while (num > 0) {
        index += num % 10;
        num = num / 10;
      }
      resultMap[index] += 1;
    }
    result = *max_element(resultMap.begin(), resultMap.end());
    return result;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.23/1742.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto lowLimit = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto highLimit = atoi(buf);
    auto ans = sol.countBalls(lowLimit, highLimit);
    std::cout << ans << std::endl;
  }
  return 0;
}
