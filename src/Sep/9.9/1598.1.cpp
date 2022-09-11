/**
 * @file 1598.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-09
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minOperations(vector<string>& logs) {
    int ans = 0;
    for (auto& log : logs) {
      if (log == "../") {
        if (ans) --ans;
      } else if (log != "./") {
        ++ans;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<string> logs{"d1/", "d2/", "../", "d21/", "./"};
  std::cout << sol.minOperations(logs) << std::endl;
  return 0;
}
