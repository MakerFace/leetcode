/**
 * @file 777.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-02
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canTransform(string start, string end) {
    int n = static_cast<int>(start.size());
    int i = 0, j = 1;
    while (i < n) {
      if (start[i] != end[i]) {
        if (j < i) j = i + 1;
        if (start[i] == 'R' and end[i] == 'X') {  // find R
          while (j < n and start[j] == 'R') ++j;
          if (j >= n or start[j - 1] == 'L') return false;
          swap(start[i], start[j]);
        } else if (start[i] == 'X' and end[i] == 'L') {  // find X
          if (j < i) j = i + 1;
          while (j < n and start[j] == 'X') ++j;
          if (j >= n or start[j] == 'R') return false;
          swap(start[i], start[j]);
        } else
          return false;
      }
      ++i;
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string start, end;
  string test_file = string(PROJECT_PATH).append("/src/Oct/10.2/test.txt");
  ifstream in(test_file);
  while (in >> start >> end) {
    std::cout << boolalpha << sol.canTransform(start, end) << std::endl;
  }
  return 0;
}
