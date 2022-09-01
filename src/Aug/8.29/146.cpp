/**
 * @file 146.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-08-29
 */
#include <bits/stdc++.h>

using namespace std;

// BUG 超时
class dlist {
 public:
  dlist(int key, int value) : _key(key), _value(value) {
    _prev = _next = nullptr;
  }
  dlist *&next() { return _next; }
  dlist *&prev() { return _prev; }
  int key() { return _key; }
  int &value() { return _value; }

 private:
  int _key;
  int _value;
  dlist *_prev;
  dlist *_next;
};

class LRUCache {
 public:
  unordered_map<int, dlist *> set;
  dlist *head;
  int capacity;
  LRUCache(int capacity) : capacity(capacity) { head = nullptr; }

  int get(int key) {
    if (set.find(key) == set.end()) {  // not found
      return -1;
    }
    auto found = set[key];
    if (found != head) {
      // remove from mid
      found->prev()->next() = found->next();
      found->next()->prev() = found->prev();
      // add to head
      found->prev() = head->prev();
      head->prev()->next() = found;
      found->next() = head;
      head->prev() = found;
      head = found;
    }
    return found->value();
  }

  void put(int key, int value) {
    if (set.find(key) == set.end()) {  // not found int hashtable
      if (head != nullptr) {           // found
        auto node = new dlist(key, value);
        // insert before head
        node->prev() = head->prev();
        head->prev() = node;
        node->next() = head;
        node->prev()->next() = node;
        head = node;
      } else {  // null list
        head = new dlist(key, value);
        head->next() = head;
        head->prev() = head;
      }
      set[key] = head;
      while (static_cast<int>(set.size()) >
             capacity) {  // overflow, erase from tail
        auto older_key = head->prev()->key();
        auto delete_node = head->prev();
        head->prev() = head->prev()->prev();
        head->prev()->next() = head;
        delete delete_node;
        set.erase(older_key);
      }
    } else {
      auto found = set[key];
      if (found != head) {
        // remove from mid
        found->prev()->next() = found->next();
        found->next()->prev() = found->prev();
        // add to head
        found->prev() = head->prev();
        head->prev()->next() = found;
        found->next() = head;
        head->prev() = found;
        head = found;
      }
      found->value() = value;
    }
  }
};

int main(int argc, char const *argv[]) {
  LRUCache obj(3);
  obj.put(1, 1);
  obj.put(2, 2);
  obj.put(3, 3);
  obj.put(4, 4);
  cout << obj.get(4) << endl;
  cout << obj.get(3) << endl;
  cout << obj.get(2) << endl;
  cout << obj.get(1) << endl;
  obj.put(5, 5);
  cout << obj.get(1) << endl;
  cout << obj.get(2) << endl;
  cout << obj.get(3) << endl;
  cout << obj.get(4) << endl;
  cout << obj.get(5) << endl;
}
