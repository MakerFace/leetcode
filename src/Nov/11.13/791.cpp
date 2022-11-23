/**
 * @file 791.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-13
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  string customSortString(string order, string s) {
    unordered_map<char, int> map(order.size());
    int j = s.size() - 1;
    int i = 0;
    for (auto c : order) {
      map[c] = i;
      ++i;
    }
    i = 0;
    while (i < j) {
      if (not map.count(s[i])) {
        swap(s[i], s[j]);
        --j;
      } else {
        ++i;
      }
    }
    int len = j;
    if (map.count(s[j])) {
      len = j + 1;
    }
    sort(s.begin(), s.begin() + len,
         [&](char a, char b) { return map[a] < map[b]; });
    sort(s.begin() + len, s.end());
    return s;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.13/791.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    string order = buf;
    in.getline(buf, MAX_LINE_SIZE);
    s = buf;
    auto ans = sol.customSortString(order, s);
    std::cout << ans << std::endl;
  }
  return 0;
}
