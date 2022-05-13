/**
 * @file 1128.cpp
 * @brief 等价多米诺骨牌对的数量
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-29
 */
#include <bits/stdc++.h>

#include "common/Matrix.hpp"
using namespace std;
class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    int result = 0;
    unordered_map<string, int> map;
    for (size_t i = 0; i < dominoes.size(); ++i) {
      string key;
      for (auto d : dominoes[i]) {
        key += d + '0';
      }
      auto iter = map.find(key);
      if (iter == map.end()) {
        reverse(key.begin(), key.end());
        iter = map.find(key);
        if (iter == map.end()) {
          map.insert(make_pair(key, 1));
        } else {
          iter->second++;
        }
      } else {
        iter->second++;
      }
    }
    for (auto var : map) {
      if (var.second > 1) {
        result += (var.second - 1) * (var.second) / 2;
      }
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  Matrix<int> dominoes = {{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}};
  std::cout << ans.numEquivDominoPairs(dominoes) << std::endl;
  return 0;
}
