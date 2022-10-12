/**
 * @file 211.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-12
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class WordDictionary {
 public:
  WordDictionary() { prefix_tree = make_unique<PrefixTree>(PrefixTree()); }

  void addWord(string word) {
    PrefixTree* root = prefix_tree.get();
    for (auto& c : word) {
      if (root->children[c - 'a'] == nullptr) {
        root->children[c - 'a'] = make_unique<PrefixTree>(PrefixTree());
      }
      root = root->children[c - 'a'].get();
    }
    root->value++;
  }

  bool search(string word) {
    return dfs(word.begin(), word.end(), prefix_tree.get());
  }

 private:
 private:
  class PrefixTree {
   public:
    array<unique_ptr<PrefixTree>, 26> children;
    int value;
  };

 private:
  bool dfs(string::iterator first, string::iterator last, PrefixTree* root) {
    if (root == nullptr) return false;
    if (first == last) {
      if (root->value)
        return true;
      else
        return false;
    }
    if (*first == '.') {
      // foreach
      for (auto& child : root->children) {
        if (child != nullptr and dfs(first + 1, last, child.get())) return true;
      }
      return false;
    } else {
      if (root->children[*first - 'a'] != nullptr)
        return dfs(first + 1, last, root->children[*first - 'a'].get());
    }
    return false;
  }

  template <typename T, typename... Args>
  std::unique_ptr<T> make_unique(Args&&... params) {
    return std::unique_ptr<T>(new T(std::forward<Args>(params)...));
  }

 private:
  unique_ptr<PrefixTree> prefix_tree;
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.12/211.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    s = buf;
    auto opt = string2vector<string>(s);
    in.getline(buf, MAX_LINE_SIZE);
    s = buf;
    auto nums = string2matrix<string>(s);
    WordDictionary* obj = nullptr;
    std::cout << "[";
    for (size_t i = 0; i < opt.size(); ++i) {
      if (opt[i] == "WordDictionary") {
        obj = new WordDictionary();
      } else if (opt[i] == "addWord") {
        obj->addWord(nums[i][0]);
        std::cout << "null"
                  << ",";
      } else if (opt[i] == "search") {
        std::cout << boolalpha << obj->search(nums[i][0]) << ",";
      }
    }
    if (not opt.empty()) {
      std::cout << "\b";
    }
    std::cout << "]" << std::endl;
    if (obj) delete obj;
  }
  return 0;
}