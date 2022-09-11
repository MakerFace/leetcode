/**
 * @file 1592.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-07
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string reorderSpaces(string text) {
    vector<string> words;
    int count = 0;
    for (auto s = text.begin(); s != text.end();) {
      while (s != text.end() and *s == ' ') {
        ++count;
        ++s;
      }
      auto e = s;
      while (e != text.end() && *e != ' ') {
        ++e;
      }
      if (s != e) {
        words.emplace_back(s, e);
      }
      s = e;
    }
    string ans;

    if (words.size() == 1) {
      ans += words[0] + string(count, ' ');
    } else {
      int span = count / (words.size() - 1);
      for (auto &word : words) {
        if (&word == &words.back()) {
          ans += word + string(count - span * (words.size() - 1), ' ');
          break;
        }
        ans += word + string(span, ' ');
      }
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string text = "Hello World";
  char buff[100];
  while (cin.getline(buff, 100)) {
    text = buff;
    std::cout << sol.reorderSpaces(text) << std::endl;
  }
  return 0;
}
