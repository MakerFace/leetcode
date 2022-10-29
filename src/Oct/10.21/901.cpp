/**
 * @file 901.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-21
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>
#include <vector>

#include "common/Matrix.hpp"
#include "common/Vector.hpp"
#include "common/utils.hpp"

using namespace std;

class StockSpanner {
public:
  StockSpanner() : idx(-1) { sta.emplace(-1, INT_MAX); }

  /**
   * @brief 单调栈，使用索引记录有多少个数小于栈顶元素
   * idx始终递增，表示已经插入多少个数
   */
  int next(int price) {
    idx++;
    while (sta.top().second <= price) {
      sta.pop();
    }
    auto ans = idx - sta.top().first;
    sta.emplace(idx, price);
    return ans;
  }

private:
  int idx;
  stack<pair<int, int>> sta;
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.21/901.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    StockSpanner sol;
    s = buf;
    auto operators = string2vector<string>(s);
    in.getline(buf, MAX_LINE_SIZE);
    s = buf;
    auto nums = string2matrix(s);
    for (size_t i = 1; i < nums.size(); ++i) {
      auto ans = sol.next(nums[i][0]);
      std::cout << ans << std::endl;
    }
  }
  return 0;
}
