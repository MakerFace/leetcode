/**
 * @file 1620.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-02
 */
#include <bits/stdc++.h>
#include <math.h>

#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "common/Matrix.hpp"
using namespace std;

class Solution {
 public:
  vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    int x2 = 0, y2 = 0;
    for (auto& tower : towers) {
      x2 = max(x2, tower[0]);
      y2 = max(y2, tower[1]);
    }
    int max_intensity = INT_MIN;
    vector<int> ans;
    for (int i = 0; i <= x2; ++i) {
      for (int j = 0; j <= y2; ++j) {
        int intensity = 0;
        for (auto&& tower : towers) {
          auto dis = distance(tower[0], tower[1], i, j);
          if (inbound(dis, radius)) {
            intensity += cacl_intensity(tower[2], dis);
          }
        }
        if (max_intensity < intensity) {
          max_intensity = intensity;
          ans = {i, j};
        }
      }
    }
    return ans;
  }

 private:
  int cacl_intensity(int q, double d) const {
    auto temp = q / (1 + d);
    return int(temp);
  }

  bool inbound(double dis, int radius) const { return radius - dis >= 0; }

  double distance(int x, int y, int i, int j) const {
    return sqrt(pow(x - i, 2) + pow(y - j, 2));
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.02/1620.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto towers = string2matrix(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto radius = atoi(buf);
    auto ans = sol.bestCoordinate(towers, radius);
    std::cout << ans << std::endl;
  }
  return 0;
}
