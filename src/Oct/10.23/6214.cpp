/**
 * @file 6214.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-23
 */
#include <bits/stdc++.h>
#include <cstdlib>

#include "common/Vector.hpp"
#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  bool haveConflict(vector<string> &event1, vector<string> &event2) {
    auto start1 = to_time(event1[0]);
    auto end1 = to_time(event1[1]);
    auto start2 = to_time(event2[0]);
    auto end2 = to_time(event2[1]);
    return not (end1 < start2 or end2 < start1);
  }

private:
  int to_time(string &time) {
    auto split = time.find(":");
    return atoi(time.substr(0, split).c_str()) * 60 +
           atoi(time.substr(split + 1, 2).c_str());
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.23/6214.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto event1 = string2vector<string>(s);
    in.getline(buf, MAX_LINE_SIZE);
    s = buf;
    auto event2 = string2vector<string>(s);
    auto ans = sol.haveConflict(event1, event2);
    std::cout << ans << std::endl;
  }
  return 0;
}
