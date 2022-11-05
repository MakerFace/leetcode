/**
 * @file offer.58.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-31
 */
#include <bits/stdc++.h>

#include <cstddef>
#include <deque>
#include <string>

using namespace std;

class Solution {
  using Iterator = string::iterator;

 public:
  string reverseWords(string s) {
    // reverse(s.begin(), s.end());
    // auto first = s.begin() - 1, middle = s.begin(), end = s.begin();
    // while (end != s.end()) {
    //   while (end != s.end() and *middle == ' ') ++middle, ++end;
    //   while (end != s.end() and *end != ' ') ++end;
    //   if (end == middle) {
    //     break;
    //   }
    //   reverse_copy_to(first + 1, middle, end);
    //   first += end - middle + 1;
    //   *(first) = ' ';
    //   middle = end;
    // }
    // if (first < s.begin()) {
    //   return "";
    // }
    // while (first < s.end() and *first == ' ') {
    //   --first;
    // }
    // s = s.substr(0, first - s.begin() + 1);
    // return s;
    deque<string> deq;
    size_t first = 0, end = 0;
    while (end < s.size()) {
      while (first < s.size() and s[first] == ' ') ++first, ++end;
      while (end < s.size() and s[end] != ' ') ++end;
      if (first == end) {
        break;
      }
      deq.emplace_back(s.substr(first, end - first));
      first = end;
    }
    s.clear();
    while (not deq.empty()) {
      s += deq.back() + " ";
      deq.pop_back();
    }
    if (not s.empty()) {
      s.pop_back();
    }
    return s;
  }

 private:
  void reverse_copy_to(Iterator idx, Iterator first, Iterator last) {
    while (idx < first) {
      *idx = *(last - 1);
      ++idx, --last;
    }
    reverse(first, last);
  }

  void reverse(Iterator first, Iterator last) {
    while (first < last) {
      swap(*first, *(last - 1));
      ++first, --last;
    }
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.31/offer.58.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto ans = sol.reverseWords(s);
    std::cout << "\"" << s << "\"" << std::endl;
    std::cout << "\"" << ans << "\"" << std::endl;
  }
  return 0;
}
