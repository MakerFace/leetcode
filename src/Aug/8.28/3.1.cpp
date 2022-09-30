/**
 * @file 3.1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-08-28
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  /**
   * @brief 双指针法，左指针指向串首，右指针指向串尾
   * 如果右指针插入失败，则左指针向右移动并删除set中的
   * 字符，直到右指针插入成功。插入过程中，set的长度即
   * 为所有不重复字符串的长度。
   */
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int ans = 0;
    int left = 0, right = 0;
    while (right < static_cast<int>(s.size())) {
      auto res = set.insert(s[right]);
      while (not res.second) {
        auto iter = set.find(s[left]);
        set.erase(iter);
        ++left;
        res = set.insert(s[right]);
      }

      ans = max(ans, static_cast<int>(set.size()));
      ++right;
    }
    ans = max(static_cast<int>(set.size()), ans);
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  string s;
  Solution sol;
  while (cin >> s) {
    cout << sol.lengthOfLongestSubstring(s) << endl;
  }
  return 0;
}
