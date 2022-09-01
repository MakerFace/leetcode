#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

/**
 * @brief 无锁编程实现N个线程顺序打印M个数
 */
std::atomic<int> count(1);

void f(int s, int n, int m) {
  int id = s;
  while (true) {
    int desire = s;
    while (not count.compare_exchange_strong(desire, s)) desire = s;
    s += n;
    std::cout << "thread_" << id << " " << count << std::endl;
    count++;
    if (s > m) break;
  }
}

int main() {
  std::vector<std::thread> v;  //实例化一个元素类型为std::thread的向量
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    v.emplace_back(f, i, n, m);
  }
  for (auto& t : v) {
    t.join();
  }
  return 0;
}