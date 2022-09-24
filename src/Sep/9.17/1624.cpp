/**
 * @file 1624.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-17
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    unordered_map<char, tuple<int, int>> map;
    int ans = -1;
    for (int i = 0; i < static_cast<int>(s.size()); i++) {
      if (map.find(s[i]) == map.end()) {
        map.emplace(s[i], make_tuple(i, i));
      } else {
        auto &range = map[s[i]];
        get<1>(range) = i;
        ans = max(ans, get<1>(range) - get<0>(range) - 1);
      }
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string s;
  while (cin >> s) {
    cout << sol.maxLengthBetweenEqualCharacters(s) << endl;
  }
  return 0;
}