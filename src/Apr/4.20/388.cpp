/**
 * @file 388.cpp
 * @brief 文件的最长绝对路径
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-20
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lengthLongestPath(string input) {
    stack<string> stack;
    size_t i = 0;
    size_t j = 0;
    int type = -1;
    int path_length = 0;
    int res = 0;
    while (j < input.size()) {
      // 前导\t数
      size_t count = 0;
      while ((j + count) < input.size() && input[j + count] == '\t') {
        ++count;
      }
      i = j += count;
      // 文件/目录名
      type = parseName(input, j);
      // 出栈直到栈和前导\t一样高
      while (stack.size() > count) {
        if (stack.empty()) {
          std::cerr << "ERROR" << std::endl;
          return -1;
        }
        path_length -= stack.top().size() + 1;
        stack.pop();
      }
      stack.push(input.substr(i, j - i));
      if (type == 1)  // dir
      {
        path_length += stack.top().size() + 1;
        // std::cout << "dir name: " << stack.top() << std::endl;
      } else if (type == 2)  // file
      {
        res = max((int)(stack.top().size() + path_length), res);
        path_length += stack.top().size() + 1;
        // std::cout << "file name: " << stack.top() << std::endl;
      }
      ++j;  ///* 略过/n
    }
    return res;
  }

 private:
  int parseName(const string &s, size_t &j) {
    int res = -1;
    for (; j < s.size(); ++j) {
      if (s[j] == '\n') {
        if (res == -1) res = 1;
        return res;
      } else if (s[j] == '.') {
        res = 2;
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str = "file1.txt\nfile2.txt\nlongfile.txt";
  auto res = s.lengthLongestPath(str);
  std::cout << res << std::endl;
  return 0;
}
