/**
 * @file 788.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-25
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int rotatedDigits(int n) {
    int ans = 0;
    bool self_flag = 0;
    array<int, 10> self{0, 1, 1, 1, 1, 1, 1, 1, 2, 2};
    array<int, 10> ones{0, 0, 1, 1, 1, 2, 3, 3, 3, 4};
    array<int, 10> each{0, 0, 0, 1, 1, 1, 2, 3, 3, 3};
    array<int, 10> digits{1, 2, 3, 3, 3, 4, 5, 5, 6, 7};
    array<int, 5> map{0, 4, 36, 276, 1941};
    if (n >= 1000) {
      ans += each[n / 100 - 1] * 7 * 7 * 7 + self[n / 100 - 1] * 4 * 7 * 7 * 3;
      ans += map[3];
    }
    if (n >= 100) {
      ans += each[n / 100 - 1] * 7 * 7 + self[n / 100 - 1] * (4 * 7 + 3 * 4);
      ans += map[2];
      self_flag = n / 100 == 0 or n / 100 == 1 or n / 100 == 8;
      n %= 100;
    }
    if (n >= 10) {
      ans += each[n / 10 - 1] * 7 + self[n / 10 - 1] * 4;
      ans += map[1];
      self_flag = n / 10 == 0 or n / 10 == 1 or n / 10 == 8;
      if (self_flag) {
        ans += ones[n % 10];
      } else {
        ans += digits[n % 10];
      }
    } else {
      ans += each[n];
    }

    return ans;
  }
};

int main(int argc, char const *argv[]) {
  int n;
  Solution sol;
  while (cin >> n) {
    std::cout << sol.rotatedDigits(n) << std::endl;
  }
  return 0;
}
