#ifndef NODE_HPP
#define NODE_HPP

#include <initializer_list>
#include <queue>
#include <vector>
#define null -1

namespace tree {
class Node {
 public:
  int val;
  std::vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, std::vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

}  // namespace tree

tree::Node *list2Tree(std::initializer_list<int> l) {
  std::queue<tree::Node *> queue;
  tree::Node *head = nullptr;
  for (auto iter = l.begin(); iter != l.end();) {
    if (queue.empty()) {
      head = new tree::Node(*iter);
      queue.push(head);
      ++iter;
    } else {
      std::vector<tree::Node *> children;
      while ((iter != l.end()) && (*iter != -1)) {
        tree::Node *temp = new tree::Node(*iter);
        children.emplace_back(temp);
        queue.push(temp);
        ++iter;
      }
      queue.front()->children.swap(children);
      queue.pop();
    }
    if (iter != l.end()) {
      ++iter;
    }
  }
  return head;
}

#endif  // NODE_HPP
