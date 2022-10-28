/**
 * @file 1822.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-27
 */
#include <fstream>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int negative = 0;
    for (auto n : nums) {
      negative += n < 0;
      if (n == 0) return 0;
    }
    return negative % 2 == 0 ? 1 : -1;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.27/1822.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto nums = string2vector(buf);
    auto ans = sol.arraySign(nums);
    std::cout << ans << std::endl;
  }
  return 0;
}
