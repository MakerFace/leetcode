/**
 * @file 904.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-17
 */
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

#include "common/Vector.hpp"
#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int type_i = fruits[0], type_j = -1;
    int right_i = 0, right_j = -1;
    int n = static_cast<int>(fruits.size());
    int ans = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (fruits[i] == type_i) {
        right_i = i;
      } else if (fruits[i] == type_j) {
        right_j = i;
      } else {
        if (fruits[i - 1] == type_i) {
          // change j
          count = right_i - right_j;
          type_j = fruits[i];
          right_j = i;
        } else {
          // change i
          count = right_j - right_i;
          type_i = fruits[i];
          right_i = i;
        }
      }
      count++;
      ans = max(ans, count);
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.17/904.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto fruits = string2vector(s);
    auto ans = sol.totalFruit(fruits);
    std::cout << ans << std::endl;
  }
  return 0;
}
