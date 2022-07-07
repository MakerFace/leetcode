/**
 * @file 121.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-22
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    size_t n = prices.size();
    int min_price = prices[0];
    int max_profit = 0;
    for (size_t i = 0; i < n; i++) {
      if (min_price > prices[i]) {
        min_price = prices[i];
      } else {
        max_profit = max(prices[i] - min_price, max_profit);
      }
    }
    return max_profit;
  }
};

int main(int argc, char const* argv[]) {
  Solution ans;
  vector<int> prices{7, 1, 5, 3, 6, 4};
  std::cout << ans.maxProfit(prices) << std::endl;
  return 0;
}
