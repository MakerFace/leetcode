/**
 * @file new_in_thread.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-12
 */

#include <atomic>
#include <iostream>
#include <thread>

class SingleClass {
 private:
  static std::atomic<SingleClass*> _instance;
  static std::atomic<bool> _lock;

 public:
  SingleClass() {
    std::cout << this << "create single calss" << std::endl;
    std::this_thread::sleep_for(
        std::chrono::milliseconds(1000));  // 模拟获取大量数据，磁盘I/O等
  }

  ~SingleClass() { delete _instance.load(); }

  static SingleClass* getInstance() {
    bool desire = false;
    while (_instance.load() ==
               nullptr and  // 如果没有实体，就使用自旋锁进入互斥区
           not _lock.compare_exchange_strong(desire, true)) {  // 获取自旋锁
      desire = false;
    }
    if (_instance.load() == nullptr) {
      std::this_thread::sleep_for(
          std::chrono::milliseconds(1000));  // 模拟线程打断（new）
      _instance.store(new SingleClass());
    }
    _lock.store(false);  // 互斥区结束
    return _instance;
  }
};

std::atomic<SingleClass*> SingleClass::_instance(nullptr);
std::atomic<bool> SingleClass::_lock(false);

int main(int argc, char const* argv[]) {
  /* code */
  auto get_single_class = []() {
    auto single_class = SingleClass::getInstance();
    std::cout << single_class << std::endl;
  };
  std::thread a(get_single_class), b(get_single_class), c(get_single_class),
      d(get_single_class);
  a.join();
  b.join();
  c.join();
  d.join();
  return 0;
}