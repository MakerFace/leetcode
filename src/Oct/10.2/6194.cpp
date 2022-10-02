/**
 * @file 6194.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-02
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minimizeXor(int num1, int num2) {
    int count1 = count(num1), count2 = count(num2);
    if (count1 == count2) return num1;
    if (count2 < count1) {  // num1后n位1置0
      count2 = count1 - count2;
      while (count2--) {
        auto last = lowbit(num1);
        num1 ^= lowbit(num1);  // 最后一位1置0
      }
      return num1;
    }
    // else // num1后n位个0置1
    count2 = count2 - count1;
    int n = 1;
    while (count2--) {
      while (num1 & n) {
        n <<= 1;
      }
      num1 |= n;
    }
    return num1;
  }

 private:
  int lowbit(int x) { return x & -x; }

  int count(int n) {
    int count = 0;
    while (n) {
      if (n & 1) count++;
      n >>= 1;
    }
    return count;
  }
};

int main(int argc, char const *argv[]) {
  int num1, num2;
  Solution sol;
  while (cin >> num1 >> num2) {
    std::cout << sol.minimizeXor(num1, num2) << std::endl;
  }

  return 0;
}
