/**
 * @file 784.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-30
 */
#include <bits/stdc++.h>

#include <cctype>
#include <functional>
#include <unordered_set>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  vector<string> letterCasePermutation(string s) {
    unordered_set<string> set;
    int n = s.size();
    function<void(int)> dfs;
    dfs = [&](int idx) {
      if (idx >= n) {
        return;
      }
      for (int i = idx; i < n; ++i) {
        auto temp = s[i];
        s[i] = toupper(s[i]);
        set.insert(s);
        dfs(i + 1);
        s[i] = tolower(s[i]);
        set.insert(s);
        dfs(i + 1);
        s[i] = temp;
      }
    };
    dfs(0);
    vector<string> ans;
    for (auto &&str : set) {
      ans.emplace_back(str);
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.30/784.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto ans = sol.letterCasePermutation(s);
    std::cout << ans << std::endl;
  }
  return 0;
}
