/**
 * @file 57_2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-11
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> res;
    for (int i = 1; i < target; i++) {
      int sum = 0;
      int j = i;
      vector<int> temp;
      while (sum < target && j < target) {
        sum += j;
        temp.push_back(j);
        if (sum == target) {
          res.push_back(temp);
          break;
        }
        j++;
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  cin >> n;
  auto res = s.findContinuousSequence(n);
  for (size_t i = 0; i < res.size(); i++) {
    for (size_t j = 0; j < res[i].size(); j++) {
      std::cout << res[i][j];
    }
    std::cout << std::endl;
  }
  return 0;
}