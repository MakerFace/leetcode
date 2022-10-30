/**
 * @file 6220.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-30
 */
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int averageValue(vector<int>& nums) {
    int count = 0;
    int sum = 0;
    for (auto n : nums) {
      if (n % 6 == 0) {
        ++count;
        sum += n;
      }
    }
    return std::floor((float)sum / count);
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.30/6220.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    // Solution sol;

    // auto ans = sol.;
    // std::cout << ans << std::endl;
  }
  return 0;
}
