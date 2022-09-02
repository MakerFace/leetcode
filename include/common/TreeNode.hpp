#pragma once
#include <bits/stdc++.h>
#define null -1

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

template <class Node = TreeNode>
Node *list2tree(std::initializer_list<int> l) {
  Node *root = nullptr;
  std::queue<Node *> q;
  int count = 0;
  for (auto &i : l) {
    if (!root) {
      root = new Node(i);
      q.push(root);
    } else {
      Node *p = nullptr;
      if (i != -1) p = new Node(i);
      if (count == 0) {
        q.front()->left = p;
      } else if (count == 1) {
        q.front()->right = p;
        q.pop();
      }
      if (p != nullptr) {
        q.push(p);
      }
      ++count;
      count %= 2;
    }
  }
  return root;
}

template <class Node = TreeNode>
Node *string2tree(std::string data) {
  Node *root = nullptr;
  std::queue<Node *> q;
  int count = 0;
  for (size_t i = 1; i < data.size() - 1; ++i) {
    size_t j = i;
    while (j < data.size() - 1) {
      if (data[j] == ',' or data[j] == ']') break;
      ++j;
    }
    auto node = [](const std::string &substr) {
      if (substr.empty()) return std::make_tuple(INT_MIN, false);
      if ((substr[0] >= '0' and substr[0] <= '9') or substr[0] == '-' or
          substr[0] == '+')
        return std::make_tuple(atoi(substr.c_str()), true);
      else
        return std::make_tuple(INT_MIN, false);
    }(data.substr(i, j - i));
    i = j;
    if (!root) {
      if (std::get<1>(node)) {
        root = new Node(std::get<0>(node));
        q.push(root);
      }
    } else {
      Node *p = nullptr;
      if (std::get<1>(node)) {
        p = new Node(std::get<0>(node));
      }
      if (count == 0) {
        q.front()->left = p;
      } else if (count == 1) {
        q.front()->right = p;
        q.pop();
      }
      if (p != nullptr) {
        q.push(p);
      }
      ++count;
      count %= 2;
    }
  }
  return root;
}

template <class Node = TreeNode>
void delete_tree(Node *root) {
  print_tree(root, true);
}

template <class Node = TreeNode>
void print_tree(Node *root, bool del_tree = false) {
  Node *null_node = new Node(-1);
  std::queue<Node *> queue;
  std::vector<int> v;
  queue.push(root);
  int curChild = 1;
  int nextChild;
  while (!queue.empty()) {
    nextChild = 0;
    for (int i = 0; i < curChild; ++i) {
      Node *temp = queue.front();
      queue.pop();
      if (!temp) break;
      if (temp->val == -1) {
        v.push_back(-1);
      } else {
        v.push_back(temp->val);
        if (temp->left != nullptr) {
          queue.push(temp->left);
        } else {
          queue.push(null_node);
        }
        ++nextChild;
        if (temp->right != nullptr) {
          queue.push(temp->right);
        } else {
          queue.push(null_node);
        }
        ++nextChild;
      }
      if (del_tree) {
        if (temp != null_node) delete temp;
      }
    }
    curChild = nextChild;
  }
  delete null_node;
  if (not del_tree) {
    std::cout << "[";
    if (!v.empty()) {
      for (auto i = v.end() - 1; i != v.begin() && *i == -1; --i) {
        v.erase(i);
      }
      if (not v.empty()) {
        std::cout << v[0];
      }
      for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] == -1)
          std::cout << ",null";
        else
          std::cout << "," << v[i];
      }
    }
    std::cout << "]";
  }
}

template <class Node = TreeNode>
void println_tree(Node *root) {
  print_tree<Node>(root);
  std::cout << std::endl;
}