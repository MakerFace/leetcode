/**
 * @file 232.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-12
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 还有一种方法
 * 只在出栈时候倒栈
 * 即s1.pop()，将s1的值都push到s2中
 * 此时s1压栈不受影响
 * 出队直接s2.pop()即可
 * 如果s2为空，那么再次执行倒栈
 *
 * 此外，取队首可以用front暂存，如果s2有值
 * 则直接返回s2.top
 * 否则返回front，只有s1为空栈时才改变
 */
class MyQueue {
 private:
  stack<int> s1, s2;
  int front;

 public:
  MyQueue() {}

  void push(int x) {
    if (s1.empty()) front = x;
    s1.push(x);
  }

  int pop() {
    if (s2.empty())
      while (not s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    int ret;
    ret = s2.top();
    s2.pop();
    return ret;
  }

  int peek() {
    if (not s2.empty()) {
      return s2.top();
    }
    return front;
  }

  bool empty() { return s1.empty() and s2.empty(); }
};

int main(int argc, char const *argv[]) {
  MyQueue q;
  q.push(1);
  q.push(2);
  std::cout << q.peek() << std::endl;
  std::cout << q.pop() << std::endl;
  std::cout << boolalpha << q.empty() << std::endl;
  return 0;
}
