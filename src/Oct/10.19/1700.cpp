/**
 * @file 1700.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-19
 */
#include <bits/stdc++.h>
#include <queue>

#include "common/Vector.hpp"
#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    queue<int> que;
    int top = 0;
    int n = static_cast<int>(sandwiches.size());
    for (int i = 0; i < n; ++i) {
      if (students[i] != sandwiches[top]) {
        que.push(students[i]);
      } else {
        top++;
      }
    }
    n = static_cast<int>(que.size());
    while (not que.empty()) {
      if (que.front() != sandwiches[top]) {
        que.push(que.front());
        que.pop();
        n--;
        if (n == 0)
          return static_cast<int>(que.size());
      } else {
        top++;
        que.pop();
        n = static_cast<int>(que.size());
      }
    }
    return 0;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.19/1700.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto students = string2vector(s);
    in.getline(buf, MAX_LINE_SIZE);
    s = buf;
    auto sandwiches = string2vector(s);
    auto ans = sol.countStudents(students, sandwiches);
    std::cout << ans << std::endl;
  }
  return 0;
}
