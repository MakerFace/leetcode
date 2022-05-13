/**
 * @file 01.05.cpp
 * @brief 面试题 01.05. 一次编辑
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-13
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool oneEditAway(string first, string second) {
    if (first.size() + 1 == second.size()) {  // 删除一个字符
      return oneInsertDelete(first, second);
    } else if (first.size() == second.size() + 1) {  // 增加一个字符
      return oneInsertDelete(second, first);
    } else if (first.size() == second.size()) {  // 修改一个字符
      auto f_iter = first.begin();
      auto s_iter = second.begin();
      size_t count = 0;
      while (f_iter != first.end() and s_iter != second.end()) {
        if (*f_iter != *s_iter) {
          if (not count) {
            *f_iter = *s_iter;
            ++count;
          } else {
            return false;
          }
        }
        ++f_iter;
        ++s_iter;
      }
    } else {
      return false;
    }
    return true;
  }

 private:
  bool oneInsertDelete(const string &first, const string &second) {
    auto f_iter = first.begin();
    auto s_iter = second.begin();
    size_t count = 0;
    while (f_iter != first.end() and s_iter != second.end()) {
      if (*f_iter == *s_iter) {
        ++f_iter;
        ++s_iter;
      } else if (not count) {
        ++s_iter;
        ++count;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  string first, second;
  Solution ans;
  while (cin >> first >> second) {
    std::cout << boolalpha << ans.oneEditAway(first, second) << std::endl;
  }
  return 0;
}
