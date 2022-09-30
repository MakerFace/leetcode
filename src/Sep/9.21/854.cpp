/**
 * @file 854.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-21
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int kSimilarity(string s1, string s2) {
    int ans = INT_MAX;

    deque<int> q;  // 记录所有需要交换的字符
    auto len = static_cast<int>(s1.size());
    for (int i = 0; i < len; ++i) {
      if (s1[i] != s2[i]) {
        q.emplace_back(i);
      }
    }
    len = static_cast<int>(q.size());

    unordered_map<string, int> map;  // key is <int,int>, value is min swap
    function<bool(int)> bfs;
    int count = 0;
    bfs = [&](int idx) {  // TODO 减枝：如果i,j交换过，那么以后的交换都跳过
      if (idx == len) return true;
      while (idx < len and s1[q[idx]] == s2[q[idx]]) {
        ++idx;
      }
      if (idx >= len) return true;
      bool found = false;
      for (int i = idx + 1; i < len; i++) {  // 从idx+1到len依次交换
        if (s2[q[i]] == s1[q[idx]]) {
          swap(s2[q[idx]], s2[q[i]]);
          count++;
          found = bfs(idx + 1);
          if (found and i == len - 1 and s1[q[i]] == s2[q[i]]) {
            ans = min(ans, count);
          }
          found = false;
          swap(s2[q[idx]], s2[q[i]]);  // 从后面找一个可以交换的
          count--;
        }
      }
      return found;
    };
    bfs(0);
    if (ans == INT_MAX) ans = 0;
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  string s1, s2;
  s1 = "abcdbdabc";
  s2 = "cababdbdc";
  s2 = "cdabcbadb";
  s1 = "abccaacceecdeea";
  s2 = "bcaacceeccdeaae";
  s1 = "bccaba";
  s2 = "abacbc";

  Solution sol;
  std::cout << sol.kSimilarity(s1, s2) << std::endl;
  return 0;
}
