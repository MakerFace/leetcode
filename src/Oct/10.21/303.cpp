/**
 * @file 303.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-21
 */
#include <bits/stdc++.h>
#include <cstddef>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

#include "common/Matrix.hpp"
#include "common/Vector.hpp"
#include "common/utils.hpp"

using namespace std;

class NumArray {
public:
  NumArray(vector<int> &nums) : nums(nums) {}

  int sumRange(int left, int right) {
    return accumulate(nums.begin() + left, nums.begin() + right + 1, 0);
  }

private:
  vector<int> nums;
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.21/303.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    auto operators = string2vector<string>(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto nums = string2matrix(buf);
    NumArray *sol;
    vector<int> ans;
    for (size_t i = 0; i < operators.size(); ++i) {
      if (operators[i] == "NumArray") {
        sol = new NumArray(nums[i]);
      } else {
        ans.emplace_back(sol->sumRange(nums[i][0], nums[i][1]));
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
