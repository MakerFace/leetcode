/**
 * @file 202.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  unordered_map<int, bool> map;

 public:
  bool isHappy(int n) {
    auto iter = map.find(n);
    while (iter == map.end()) {
      if (n == 1) break;
      map.insert(make_pair(n, true));
      int temp = 0;
      while (n) {
        temp += pow(n % 10, 2);
        n /= 10;
      }

      n = temp;
      iter = map.find(n);
    }
    return n == 1;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  for (int n = 1; n < 2147483647; n++) {
    cout << boolalpha << ans.isHappy(n) << endl;
  }

  return 0;
}
