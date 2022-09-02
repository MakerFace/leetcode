/**
 * @file 1475.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-01
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  /// @brief 暴力解法：时间复杂度O(n^2)；单调栈：O(n)
  /// @param prices
  /// @return
  vector<int> finalPrices(vector<int>& prices) {
    vector<int> res(prices.size());
    /****************暴力解法**********
    for (size_t i = 0; i < prices.size(); i++) {
      size_t j = i + 1;
      for (; j < prices.size(); j++) {
        if (prices[i] >= prices[j]) {
          break;
        }
      }
      if (j == prices.size()) {
        res[i] = prices[i];
        continue;
      }
      res[i] = prices[i] - prices[j];
    }
    *********************************/
    stack<int> sta;
    for (int i = prices.size() - 1; i >= 0; i--) {
      while (not sta.empty() and
             sta.top() > prices[i]) {  // 如果插入不单调，就弹栈直到单调
        sta.pop();
      }
      if (not sta.empty()) {
        res[i] -= sta.top();
      }
      res[i] += prices[i];
      sta.push(prices[i]);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> prices({8, 4, 6, 2, 3});
  Solution sol;
  print_vector(sol.finalPrices(prices));
  return 0;
}
