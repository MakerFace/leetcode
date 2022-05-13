/**
 * @file 43.cpp
 * @brief 字符串相乘
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-07
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    string result;
    size_t n1 = num1.size();
    size_t n2 = num2.size();
    for (int i = n1 - 1; i >= 0; --i) {
      for (int j = n2 - 1; j >= 0; --j) {
        int tmp = (num1[i] - '0') * (num2[j] - '0');
        size_t cur = n1 - i + n2 - j - 2;
        do {
          if (cur >= result.size()) {
            result += '0';
          }
          tmp += result[cur] - '0';
          result[cur] = tmp % 10 + '0';
          tmp /= 10;
          ++cur;
        } while (tmp);
      }
    }
    for (int i = result.size() - 1; i > 0; --i) {
      if (result[i] == '0') {
        result.erase(i);
      } else {
        break;
      }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  string num1, num2;
  while (cin >> num1 >> num2) {
    std::cout << ans.multiply(num1, num2) << std::endl;
  }
  return 0;
}
