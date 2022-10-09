#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *vector2list(std::initializer_list<int> v) {
  ListNode *head = nullptr;
  ListNode *ptr;
  for (auto var : v) {
    if (head == nullptr) {
      head = new ListNode(var);
      ptr = head;
    } else {
      ptr->next = new ListNode(var);
      ptr = ptr->next;
    }
  }
  return head;
}

ListNode *vector2list(std::vector<int> v) {
  ListNode *head = nullptr;
  ListNode *ptr;
  for (auto var : v) {
    if (head == nullptr) {
      head = new ListNode(var);
      ptr = head;
    } else {
      ptr->next = new ListNode(var);
      ptr = ptr->next;
    }
  }
  return head;
}

void print_list(const ListNode *root, std::ostream &out = std::cout) {
  out << "[";
  if (root != nullptr) {
    out << root->val;
    root = root->next;
  }
  while (root != nullptr) {
    out << "," << root->val;
    root = root->next;
  }
  out << "]" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const ListNode *root) {
  print_list(root, out);
  return out;
}

#endif  // LISTNODE_HPP
