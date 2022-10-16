/**
 * @file 341.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-14
 */
#include <bits/stdc++.h>

#include "common/NestedInteger.hpp"
#include "common/utils.hpp"

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
  using ConstNestedIterator = std::vector<NestedInteger>::const_iterator;
  const ConstNestedIterator END_ITER = std::vector<NestedInteger>().end();

 public:
  /**
   * @brief 不能复制原有数据！也不能改变原有结构！
   */
  NestedIterator(vector<NestedInteger> &nestedList) {
    // TODO remove make_pair, use std::move avoid
    sta.emplace(make_pair(
        nestedList.begin(),
        nestedList.end()));  // BUG move之后，第一个list的integer变为true？
    // FIXED
  }

  int next() { return cur->getInteger(); }

  bool hasNext() {
    while (not sta.empty()) {
      pair<ConstNestedIterator, ConstNestedIterator> &top = sta.top();
      if (top.first >= top.second) {
        sta.pop();
        continue;
      }
      if (top.first->isInteger()) {
        cur = top.first;
        top.first++;
        return true;
      } else {
        sta.emplace(make_pair(top.first->getList().begin(),
                              top.first->getList().end()));
        top.first++;
      }
    }
    return false;
  }

 private:
  stack<pair<ConstNestedIterator, ConstNestedIterator>>
  // stack<const vector<NestedInteger>&>
      sta;  // BUG **引用**将亡值
  // FIXED 去掉引用！！！不要在容器中使用引用，除非你很确定生命周期
  // FIXED 使用vector迭代器辅助实现
  ConstNestedIterator cur;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.14/341.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    s = buf;
    auto nested_list = string2nested_list(s);
    NestedIterator sol(nested_list);
    while (sol.hasNext()) {
      auto ans = sol.next();
      std::cout << ans << std::endl;
    }
  }
  return 0;
}
