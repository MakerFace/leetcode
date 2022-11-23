/**
 * @file 1704.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-11-11
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool halvesAreAlike(string s) {
    int countf = 0, countb = 0;
    for (int i = 0; i < s.size() / 2; ++i) {
      countf += egg(s[i]);
    }
    for (int i = s.size() / 2; i < s.size(); ++i) {
      countb += egg(s[i]);
    }
    return countf == countb;
  }

 private:
  int egg(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or
           c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U';
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Nov/11.11/1704.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    auto ans = sol.halvesAreAlike(s);
    std::cout << ans << std::endl;
  }
  return 0;
}
