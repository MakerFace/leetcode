/**
 * @file 707.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-23
 */

#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node {
  T value;
  Node *next;
  Node(T val = 0, Node *next = nullptr) : value(val), next(next) {}
};

class MyLinkedList {
  using Node_t = Node<int>;
  using NodePtr = Node_t *;

 public:
  MyLinkedList() : head(new Node_t()), tail(head), size(0) {}
  ~MyLinkedList() {
    while (head) {
      auto del_p = head;
      head = head->next;
      delete del_p;
    }
    head = nullptr;
    tail = nullptr;
  }

  int get(int index) {
    auto it = find(index);
    if (not it or not it->next) return -1;
    return it->next->value;
  }

  void addAtHead(int val) {
    if (size == 0) {
      addAtTail(val);
    } else {
      auto newNode = new Node_t(val);
      newNode->next = head->next;
      head->next = newNode;
      ++size;
    }
  }

  void addAtTail(int val) {
    tail->next = new Node_t(val);
    tail = tail->next;
    ++size;
  }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > size)
      return;
    else if (index == 0) {  // 等于0，插入头
      addAtHead(val);
    } else if (index == size) {  // 等于链表长度，附加到尾部
      addAtTail(val);
    } else {  // 中间插入
      auto p = find(index);
      assert(p != nullptr);
      p->next =                      // p的next指向新节点
          new Node_t(val, p->next);  // p的next给新节点next
      ++size;
    }
  }

  void deleteAtIndex(int index) {
    auto p = find(index);  // 找前一个
    if (not p) return;
    NodePtr del_p = p->next;
    assert(del_p != nullptr);     // 被删除节点必不可能为空节点
    if (del_p == tail) tail = p;  // 被删除节点是尾节点
    if (p == head) head->next = del_p->next;  // 被删除节点是头节点
    p->next = del_p->next;                    // 删除节点
    delete del_p;
    --size;
  }

 private:
  /**
   * @brief find prev
   */
  NodePtr find(int index) {
    if (size == 0 or index < 0 or index >= size) return nullptr;
    auto p = head;
    for (int i = 0; i < index; i++) p = p->next;
    return p;
  }

 private:
  NodePtr head, tail;
  int size;
};

int main(int argc, char const *argv[]) {
  /* code

   */
  vector<string> opt{"MyLinkedList", "addAtHead", "get",
                     "addAtHead",    "addAtHead", "deleteAtIndex",
                     "addAtHead",    "get",       "get",
                     "get",          "addAtHead", "deleteAtIndex"};
  vector<vector<int>> nums{{},  {4}, {1}, {1}, {5}, {3},
                           {7}, {3}, {3}, {3}, {1}, {4}};
  MyLinkedList *sol = nullptr;
  auto len = static_cast<int>(opt.size());
  for (int i = 0; i < len; i++) {
    if (opt[i] == "MyLinkedList") {
      sol = new MyLinkedList();
    } else if (opt[i] == "addAtHead") {
      sol->addAtHead(nums[i][0]);
    } else if (opt[i] == "addAtTail") {
      sol->addAtTail(nums[i][0]);
    } else if (opt[i] == "addAtIndex") {
      sol->addAtIndex(nums[i][0], nums[i][1]);
    } else if (opt[i] == "deleteAtIndex") {
      sol->deleteAtIndex(nums[i][0]);
    } else if (opt[i] == "get") {
      std::cout << sol->get(nums[i][0]) << std::endl;
    }
  }
  if (sol) {
    delete sol;
  }
  return 0;
}
