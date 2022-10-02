/**
 * @file zyk.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-28
 */
#include <bits/stdc++.h>

#include <common/utils.hpp>
using namespace std;

bool compare(int x, int y) { return x <= y; }
int main() {
  int n, m;
  cin >> n >> m;
  vector<array<int, 2>> nums(n, array<int, 2>());
  for (int i = 0; i < n; ++i) {
    cin >> nums[i][0] >> nums[i][1];
  }
  return 0;
}