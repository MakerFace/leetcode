/**
 * @file 1282.cpp
 * @brief 用户分组
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-12
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
    unordered_map<int, vector<int>> map;
    for (size_t i = 0; i < groupSizes.size(); i++) {
      auto it = map.find(groupSizes[i]);
      if (it == map.end()) {
        map.insert(pair<int, vector<int>>(groupSizes[i], {(int)i}));
      } else {
        it->second.emplace_back(i);
      }
    }
    vector<vector<int>> res;
    for (auto var : map) {
      for (size_t i = 0; i < var.second.size();) {
        vector<int> temp;
        temp.resize(var.first);
        int idx = 0;
        for (int j = 0; j < var.first; idx++, i++, j++) {
          temp[idx] = var.second[i];
        }
        res.push_back(temp);
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> groupSize = {2, 1, 3, 3, 3, 2};
  auto res = s.groupThePeople(groupSize);
  for (size_t i = 0; i < res.size(); i++) {
    for (size_t j = 0; j < res[i].size(); j++) {
      std::cout << res[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
