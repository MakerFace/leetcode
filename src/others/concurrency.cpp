/**
 * @file concurrency.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-15
 */
#include <atomic>
#include <chrono>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <stack>
#include <thread>
#include <vector>

namespace chen {

/**
 * @brief 栈节点
 * @tparam T
 */
template <typename T>
struct Node {
  T data;
  Node* next;
  Node(const T& data) : data(data), next(nullptr) {}
};
/**
 * @brief 链栈
 * @tparam T
 */
template <typename T>
class stack {
  std::atomic<Node<T>*> head;
  // std::atomic<std::shared_ptr<Node<int, std::vector<int>>>> head;

 public:
  void push(const T& data) {
    auto new_node = new Node<T>(data);
    // TODO 内存顺序
    new_node->next = head.load(std::memory_order_relaxed);

    // 令new_node为新head
    // 但如果head不是new_node->next（其它线程必须在刚才插入节点）
    // 则放新head到new_new->next中再尝试
    while (!head.compare_exchange_weak(
        new_node->next, new_node,  // 尝试将head赋值为new_node
        std::memory_order_release, std::memory_order_relaxed))
      ;
  }
  Node<T>* get_container() { return head.load(); }
  bool empty() { return head.load() == nullptr; }
  T& top() { return head.load()->data; }
  void pop() {  // TODO 不检查空栈，交给用户检查
    auto del_node = head.load();
    // TODO 循环中检查空栈
    while (not head.compare_exchange_weak(
        del_node,  // 如果head没变，那么del_node也不变，条件成立；如果head变了，那么del_node变为新head
        del_node->next,  // head等于del_node->next
        std::memory_order_release, std::memory_order_relaxed))
      ;
    delete del_node;
  }
};

}  // namespace chen

chen::stack<std::tuple<int, std::vector<int>>> s;

void doAsyncWork(int id, int finish) {
  int i = id;
  for (int i = id; i <= finish; i += 4) {
    int desire = i;
    // while (not count.compare_exchange_strong(  // swap faild
    //     desire, i)) {                          // if n ==i swap: n=i+1, i=n
    //   desire = i;
    // }
    std::cout << "thread " << id << ":" << i << std::endl;
    s.push(std::make_tuple(id, std::vector<int>(i)));
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // count++;
  }
}

int main(int argc, char const* argv[]) {
  int n = 100;
  std::thread t0(doAsyncWork, 0, n), t1(doAsyncWork, 1, n),
      t2(doAsyncWork, 2, n), t3(doAsyncWork, 3, n);
  t0.detach();
  t1.detach();
  t2.detach();
  t3.join();
  // auto ans = s.get_container();
  while (not s.empty()) {
    int id;
    std::vector<int> val;
    std::tie(id, val) = s.top();
    std::cout << "thread" << id << ":" << val.size() << std::endl;
    s.pop();
  }
  return 0;
}
