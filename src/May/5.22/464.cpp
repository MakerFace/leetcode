/**
 * @file 464.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-22
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 深度优先遍历
 */
class Solution {
 private:
  std::array<bool, 1 << 20> used_nums;
  int desiredTotal;
  int maxChoosableInteger;

 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (maxChoosableInteger >= desiredTotal) {  // 一步到达
      return true;
    }
    if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 <
        desiredTotal) {  // 都选完了还没达到
      return false;
    }
    this->desiredTotal = desiredTotal;
    this->maxChoosableInteger = maxChoosableInteger;
    return dfs(0, 0);
  }

 private:
 /**
  * @brief 递归搜索[1,max]，
  */
  bool dfs(int usedNumber, int currentTotal) {
    if (not used_nums[usedNumber]) {  // 记忆化搜索
      bool res = false;
      for (int i = 0; i < maxChoosableInteger; i++) {
        if (not((usedNumber >> i) & 1)) {  // 还未使用该数字
          if (i + 1 + currentTotal >= desiredTotal) {
            res = true;
            break;
          }
          if (not dfs(usedNumber | (1 << i), i + 1 + currentTotal)) {
            res = true;
            break;
          }
        }
      }
      used_nums[usedNumber] = res;
    }
    return used_nums[usedNumber];
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  int maxChoosableInteger, desiredTotal;
  while (cin >> maxChoosableInteger >> desiredTotal) {
    std::cout << boolalpha << ans.canIWin(maxChoosableInteger, desiredTotal)
              << std::endl;
  }
  return 0;
}
