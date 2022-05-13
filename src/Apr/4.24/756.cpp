/**
 * @file 756.cpp
 * @brief 金字塔转换矩阵
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-24
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool pyramidTransition(string bottom, vector<string> &allowed) {
    stack<int> queue;
    unordered_map<string, vector<int>> map;

    for (size_t i = 0; i < allowed.size(); ++i) {
      string key = allowed[i].substr(0, 2);
      auto iter = map.find(key);
      if (iter == map.end()) {
        map.insert(make_pair(key, vector<int>({(int)i})));
      } else {
        iter->second.push_back(i);
      }
    }
    for (size_t i = 1; i < bottom.size(); ++i) {
      string key = bottom.substr(i - 1, 2);
      auto iter = map.find(key);
      if (iter == map.end()) {
        return false;
      } else {
      }
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  string bottom;
  vector<string> allowed = {};
  std::cout << boolalpha << ans.pyramidTransition(bottom, allowed) << std::endl;
  return 0;
}
