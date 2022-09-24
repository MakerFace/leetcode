/**
 * @file 1640.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-22
 */

#include <bits/stdc++.h>

#include <common/Matrix.hpp>

using namespace std;
class Solution {
 public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    int len = static_cast<int>(pieces.size());
    unordered_map<int, int> map;
    for (int i = 0; i < len; ++i) {
      map[pieces[i][0]] = i;
    }

    len = static_cast<int>(arr.size());
    for (int i = 0; i < len;) {
      if (map.find(arr.at(i)) != map.end()) {
        // i += pieces.at(map[arr.at(i)]).size();
        int idx = map[arr.at(i)];
        int temp_len = pieces.at(idx).size();
        int j = 0;
        while (i < static_cast<int>(arr.size()) and j < temp_len and
               arr[i] == pieces[idx][j]) {
          ++i;
          ++j;
        }
        if (j < temp_len) return false;
      } else
        return false;
    }
    return true;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> arr{91, 4, 64, 78};
  Matrix<int> pieces{{78}, {4, 64}, {91}};
  Solution sol;
  std::cout << boolalpha << sol.canFormArray(arr, pieces) << std::endl;
  return 0;
}
