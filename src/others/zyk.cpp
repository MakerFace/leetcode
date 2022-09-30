/**
 * @file zyk.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-28
 */
#include <bits/stdc++.h>
using namespace std;

bool compare(int x, int y) { return x <= y; }
int main() {
  vector<int> nums = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                      2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  auto compare = [](int x, int y) { return (x < y); };
  // sort(nums.begin(), nums.end(), compare);
  sort(nums.begin(), nums.end(), compare);
  for (size_t i = 0; i < nums.size(); ++i) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
}