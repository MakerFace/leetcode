/**
 * @file 71.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-11
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> s;
    for (size_t i = 1; i < path.size(); i++) {
      size_t j = i;
      while (j < path.size()) {
        if (path[j] == '/') break;
        ++j;
      }
      string dir = path.substr(i, j - i);
      i = j;
      if (dir == "." or dir == "/" or dir == "") {
        continue;
      } else if (dir == "..") {
        if (s.size() > 0) {
          s.erase(s.end() - 1);
        }
      } else {
        s.emplace_back(dir);
      }
    }
    string result = "/";
    for (auto str : s) {
      result += str + "/";
    }
    if (result.size() > 1) {
      result.erase(result.end() - 1);
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  string path;
  while (cin >> path) {
    std::cout << ans.simplifyPath(path) << std::endl;
  }
  return 0;
}
