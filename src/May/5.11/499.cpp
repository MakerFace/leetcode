/**
 * @file 499.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-11
 */
#include <bits/stdc++.h>

#include "common/TreeNode.hpp"
using namespace std;

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    TreeNode *null_node = new TreeNode(-1);
    std::queue<TreeNode *> queue;
    std::vector<int> v;
    queue.push(root);
    int curChild = 1;
    int nextChild;
    while (!queue.empty()) {
      nextChild = 0;
      for (int i = 0; i < curChild; ++i) {
        TreeNode *temp = queue.front();
        queue.pop();
        if (!temp) break;
        if (temp->val == -1) {
          // std::cout << "null,";
          v.push_back(-1);
        } else {
          // std::cout << temp->val << ",";
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
      }
      curChild = nextChild;
    }
    string result = "[";
    if (!v.empty()) {
      for (auto i = v.end() - 1; i != v.begin() && *i == -1; --i) {
        v.erase(i);
      }
      result += to_string(v[0]);
      for (int i = 1; i < v.size(); ++i) {
        if (v[i] == -1)
          result += ",null";
        else
          result += "," + to_string(v[i]);
      }
    }
    result += "]";
    return result;
  }

  /**
   * @brief Decodes your encoded data to tree.
   * @param  data [] or [x, y, z]
   * @return TreeNode* root of search tree
   */
  TreeNode *deserialize(string data) {
    TreeNode *root = nullptr;
    std::queue<TreeNode *> q;
    int count = 0;
    for (int i = 1; i < data.size() - 1; ++i) {
      int j = i;
      while (j < data.size() - 1) {
        if (data[j] == ',' or data[j] == ']') break;
        ++j;
      }
      auto node = substr2value(data.substr(i, j - i));
      i = j;
      if (!root) {
        if (get<1>(node)) {
          root = new TreeNode(get<0>(node));
          q.push(root);
        }
      } else {
        TreeNode *p = nullptr;
        if (get<1>(node)) {
          p = new TreeNode(get<0>(node));
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

 private:
  tuple<int, bool> substr2value(const string &substr) {
    if (substr.empty()) return make_tuple(INT_MIN, false);
    if (substr[0] >= '0' and substr[0] <= '9')
      return make_tuple(atoi(substr.c_str()), true);
    else
      return make_tuple(INT_MIN, false);
  }
};

int main(int argc, char const *argv[]) {
  Codec codec;
  auto root = list2tree({});
  auto res = codec.serialize(root);
  std::cout << res << std::endl;
  auto res2 = codec.deserialize("[]");
  println_tree(res2);
  std::cout << std::endl;
  return 0;
}
