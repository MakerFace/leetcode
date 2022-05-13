/**
 * @file 28.cpp
 * @brief 实现stgrStr()
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-21
 */
#include <bits/stdc++.h>
using namespace std;

// KMP
class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle == "") return 0;
    /* 暴力查找
    for (int i = 0; i < haystack.size(); ++i)
    {
        int j = 0;
        for (; j < needle.size(); ++j)
        {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (j == needle.size())
            return i;
    }
    */
    // KMP
    vector<size_t> pre = preFun(needle);
    // find
    for (size_t i = 0, j = 0; i < haystack.size(); ++i) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = pre[j - 1];
      }
      if (haystack[i] == needle[j]) ++j;
      if (j == needle.size()) return i - needle.size() + 1;
    }
    return -1;
  }

 private:
  /**
   * @brief 求解前缀函数
   * 真前缀等于真后缀的最长真前缀长度
   * 真前缀和真后缀不等于串长
   */
  vector<size_t> preFun(string str) {
    vector<size_t> res(str.size());
    // 增量求解，复杂度O(m)
    for (size_t i = 1, j = 0; i < str.size(); ++i) {
      while (j > 0 && str[i] != str[j]) {
        j = res[j - 1];
      }
      if (str[i] == str[j]) ++j;
      res[i] = j;
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::cout << s.strStr("aaababbaba", "asdfadsf") << std::endl;
  return 0;
}
