/**
 * @file stack_test.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-14
 */
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

struct test {
  int a;
  test(int a) : a(a) { std::cout << "constructor" << a << std::endl; }
  ~test() { std::cout << "destructor" << a << std::endl; }
};

int main(int argc, char const* argv[]) {
  stack<vector<test>> sta;
  sta.emplace(vector<test>(1, {10}));
  auto& top = sta.top();
  sta.pop();
  top.emplace_back(100);
  std::cout << top[1].a << std::endl;
  return 0;
}
