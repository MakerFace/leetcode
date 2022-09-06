/**
 * @file 828.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-06
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  /**
   * @brief
   * 添加一个字符s[i]到s中，如果没有出现则当前长度为d[i+1]=d[i]+i+1即之前所有串都+1，s[1]再+1
   * 如果出现一次，那么从i到第一次出现的区间所有串长度+1，第一次出现到开头所有串长度-1
   * 如果多次出现，那么从i到最后一次出现的区间所有串长度+1，从最后一次出现的到倒数第二次出现的位置之间的串长度-1
   */
  int uniqueLetterString(string s) {
    int n = s.size();
    vector<int> dp(n + 1);
    unordered_map<char, tuple<int, int>> map;
    dp[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (map.find(s[i]) == map.end()) {  // not found in map
        map[s[i]] = make_tuple(i, -1);
        dp[i + 1] = dp[i] + i + 1;
      } else {  // s[i] in map
        auto& index = map[s[i]];
        if (get<1>(index) == -1) {  // only once
          dp[i + 1] = dp[i] - 2 * get<0>(index) + i - 1;
        } else {  // many times
          dp[i + 1] =
              dp[i] - 2 * get<0>(index) + get<1>(index) + i;  // 第N次出现的位置
        }
        get<1>(index) = get<0>(index);
        get<0>(index) = i;
      }
      ans += dp[i + 1];
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  string s;
  while (cin >> s) {
    cout << sol.uniqueLetterString(s) << endl;
  }
  return 0;
}
