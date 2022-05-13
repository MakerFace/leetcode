/**
 * @file 190.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 分治
 * 左右手翻转
 */
class Solution {
  uint32_t M1 = 0x55555555;  // 01010101010101010101010101010101
  uint32_t M2 = 0x33333333;  // 00110011001100110011001100110011
  uint32_t M4 = 0x0F0F0F0F;  // 00001111000011110000111100001111
  uint32_t M8 = 0x00FF00FF;  // 00000000111111110000000011111111

 public:
  uint32_t reverseBits(uint32_t n) {
    // int result = 0;
    // for (size_t i = 0; i < 32; i++) {
    //   result <<= 1;
    //   result += n & 0x1;
    //   n >>= 1;
    // }
    // return result;
    n = (n >> 1 & M1) | (n & M1) << 1;
    n = (n >> 2 & M2) | (n & M2) << 2;
    n = (n >> 4 & M4) | (n & M4) << 4;
    n = (n >> 8 & M8) | (n & M8) << 8;
    n = (n >> 16) | (n << 16);
    return n;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  uint32_t n;
  while (cin >> n) std::cout << ans.reverseBits(n) << std::endl;
  return 0;
}
