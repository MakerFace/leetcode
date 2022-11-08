/**
 * @file 816.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-07
 */
#include <bits/stdc++.h>

#include <atomic>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  vector<string> ambiguousCoordinates(string s) {
    s = s.substr(1, s.size() - 2);  // 去掉首尾()
    vector<string> ans;
    int i = 0;
    const int n = s.size();
    for (int i = 0; i < n; ++i) {
      auto front = help(s.substr(0, i));
      auto back = help(s.substr(i));
      if (front.empty() or back.empty()) {
        continue;
      }
      for (auto&& f : front) {
        for (auto&& b : back) {
          ans.emplace_back("(" + f + ", " + b + ")");
        }
      }
    }
    return ans;
  }

 private:
  vector<string> help(const string& s) {
    vector<string> ans;
    if (s.empty()) {
      return ans;
    }
    if (s.size() == 1) {
      ans.emplace_back(s);
      return ans;
    }
    if (s.front() == '0' and s.back() == '0') {  // 不允许前后都有0
      return ans;
    }
    if (s.front() == '0') {  // 必须变为0.xxx，且只有一份
      auto temp = s;
      temp.insert(1, ".");
      ans.emplace_back(temp);
    } else if (s.back() == '0') {  // 后有0，不能加.，只有一份
      ans.emplace_back(s);
    } else {  //前后都没有0
      ans.emplace_back(s);
      for (int i = 1; i < s.size(); ++i) {
        auto temp = s;
        temp.insert(i, ".");
        ans.emplace_back(temp);
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.07/816.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto ans = sol.ambiguousCoordinates(s);
    std::cout << ans << std::endl;
  }
  return 0;
}
