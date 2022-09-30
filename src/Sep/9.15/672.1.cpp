/**
 * @file 672.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-15
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  /**
   * @brief 前6个灯状态一致是一个周期
   * 灯1：1，3，4影响
   * 灯2：1，2影响
   * 灯3：1，3影响
   * 灯4：1，2，4影响
   * 灯5：1，3影响
   * 灯6：1，2影响
   * 合并状态，灯2，6和灯3，5，所以只有**灯1，2，3，4**会受开关影响，灯5，6随灯3，2变化
   * 假设开关1，2，3，4按下次数为a, b, c, d；
   * 灯1状态=(a+c+d)%2
   * 灯2状态=(a+b)%2
   * 灯3状态=(a+c)%2
   * 灯4状态=(a+b+d)%2
   * 根据前3个灯的状态可以推算出第四个灯的状态，所以只需要看前3个灯
   * 初始为111
   * 按一次：4种状态
   * 1：000 2：101  3：010  4：001
   * 按两次：7种状态（无011）
   * 11：111 12：010 13：101 14：100
   * 21：010 22：111 23：000 24：001
   * 31：101 32：000 33：111 34：110
   * 41：100 42：001 43：110 44：111
   * 按N>=3次：8种状态
   */
  int flipLights(int n, int presses) {
    if (presses == 0) return 1;
    if (n == 1) return 2;
    if (n == 2) return presses == 1 ? 3 : 4;  // 2个灯最多4种状态
    return presses == 1 ? 4 : presses == 2 ? 7 : 8;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  int n, presses;
  while (cin >> n >> presses) {
    std::cout << sol.flipLights(n, presses) << std::endl;
  }
  return 0;
}
