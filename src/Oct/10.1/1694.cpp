/**
 * @file 1694.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-01
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string reformatNumber(string number) {
    int l = 0, r = 0;
    int n = static_cast<int>(number.size());
    int count = 0;
    while (r < n) {
      while (r < n and (number[r] < '0' or number[r] > '9')) {
        r++;
      }
      if (r < n) number[l++] = number[r++];
      ++count;
      if (count % 3 == 0) {
        if (l == r) {
          number.insert(l, 1, '-');
          ++l, ++r;
          n++;
        } else {
          number[l++] = '-';
        }
      }
    }
    if (number[l - 1] == '-') {
      l--;
    }
    // number = number.substr(0, l);
    number.erase(number.begin() + l, number.end());
    if (number[l - 2] == '-') swap(number[l - 2], number[l - 3]);
    return number;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string number;
  char buf[101];
  while (cin.getline(buf, 101)) {
    number = buf;
    std::cout << sol.reformatNumber(number) << std::endl;
  }

  return 0;
}
