/**
 * @file 537.cpp
 * @brief 复数求和
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-02-25
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string complexNumberMultiply(string num1, string num2) {
    int a1 = getReal(num1);
    int b1 = getIm(num1);
    int a2 = getReal(num2);
    int b2 = getIm(num2);
    string res;
    res += to_string(a1 * a2 - b1 * b2);
    res += "+";
    res += to_string(a1 * b2 + a2 * b1);
    res += "i";
    return res;
  }

 private:
  int getReal(string num) {
    for (size_t i = 0; i < num.size(); i++) {
      if (num[i] == '+') {
        return atoi(num.substr(0, i).c_str());
      }
    }
    return -1;
  }

  int getIm(string num) {
    for (size_t i = 0; i < num.size(); i++) {
      if (num[i] == '+') {
        return atoi(num.substr(i + 1, num.size() - 2).c_str());
      }
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  string num1 = "1+-1i";
  string num2 = "1+-1i";
  Solution s;
  auto res = s.complexNumberMultiply(num1, num2);
  std::cout << res << std::endl;
  return 0;
}
