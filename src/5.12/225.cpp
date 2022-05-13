/**
 * @file 225.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

class MyStack {
  queue<int> q1;

 public:
  MyStack() {}

  void push(int x) { q1.push(x); }

  int pop() {
    int temp = q1.size() - 1;
    while (temp) {
      q1.push(q1.front());
      q1.pop();
      --temp;
    }
    temp = q1.front();
    q1.pop();
    return temp;
  }

  int top() { return q1.back(); }

  bool empty() { return q1.empty(); }
};

int main(int argc, char const *argv[]) {
  MyStack s;
  s.push(1);
  s.push(2);
  std::cout << s.top() << std::endl;
  std::cout << s.pop() << std::endl;
  std::cout << boolalpha << s.empty() << std::endl;
  return 0;
}
