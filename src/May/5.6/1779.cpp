/**
 * @file 1779.cpp
 * @brief 找到最近的有相同 X 或 Y 坐标的点
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
    size_t result = -1;
    int dis = INT_MAX;
    for (size_t i = 0; i < points.size(); ++i) {
      int _x = points[i][0], _y = points[i][1];
      if (_x == x or _y == y) {
        int temp = abs(x - _x) + abs(y - _y);
        if (temp < dis) {
          result = i;
          dis = temp;
        } else if (temp == dis) {
          result = min(i, result);
        }
      }
    }
    return (int)result;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  int x = 3, y = 4;
  vector<vector<int>> points = {{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};
  std::cout << ans.nearestValidPoint(x, y, points) << std::endl;
  return 0;
}
