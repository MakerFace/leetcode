#ifndef NESTED_INTEGER_HPP
#define NESTED_INTEGER_HPP
#include <string>
#include <vector>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
 public:
  NestedInteger() : _integer(false), _value(INT_MAX) {
    // std::cout << "constructor" << std::endl;
  }

  NestedInteger(int&& value) : _integer(true), _value(value) {
    // std::cout << "constructor_int:";
    // if (_integer)
    //   std::cout << _value << std::endl;
    // else
    //   std::cout << "list" << std::endl;
  }

  NestedInteger(const NestedInteger& nestedInteger)
      : _integer(nestedInteger._integer),
        _value(nestedInteger._value),
        _nested_list(nestedInteger._nested_list) {
    // std::cout << "copy constructor:";
    // if (_integer)
    //   std::cout << _value << std::endl;
    // else
    //   std::cout << "list" << std::endl;
  }

  NestedInteger(NestedInteger&& nestedInteger)
      : _integer(nestedInteger._integer),
        _value(nestedInteger._value),
        _nested_list(std::move(nestedInteger._nested_list)) {
    // std::cout << "move constructor:";
    // if (_integer)
    //   std::cout << _value << std::endl;
    // else
    //   std::cout << "list" << std::endl;
  }

  void operator=(NestedInteger&& nestedInteger) {
    _integer = nestedInteger._integer;
    _value = nestedInteger._value;
    _nested_list.swap(nestedInteger._nested_list);
  }

  // ~NestedInteger() {
  //   std::cout << "destructor:";
  //   if (_integer)
  //     std::cout << _value << std::endl;
  //   else
  //     std::cout << "list" << std::endl;
  // }
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const std::vector<NestedInteger>& getList() const;

  friend std::vector<NestedInteger> string2nested_list(const std::string& s);

 private:
  bool _integer;
  int _value;
  std::vector<NestedInteger> _nested_list;
};

bool NestedInteger::isInteger() const { return _integer; }

int NestedInteger::getInteger() const { return _value; }

const std::vector<NestedInteger>& NestedInteger::getList() const {
  return _nested_list;
}

std::vector<NestedInteger> string2nested_list(const std::string& s) {
  std::stack<NestedInteger> sta;
  std::string temp;
  for (auto c : s) {
    if (c == '[')
      sta.emplace();
    else if (c == ']') {
      auto top = std::move(sta.top());  // BUG 引用将亡值(pop后消亡)
                                        // XXX 使用std::move
      if (not temp.empty()) {
        top._nested_list.emplace_back(  // XXX vector<T> 扩容导致
            atoi(temp.c_str()));  // BUG 触发多次构造函数和多次拷贝构造函数
        temp.clear();
      }
      sta.pop();
      if (not sta.empty()) {
        sta.top()._nested_list.emplace_back(std::move(top));
      } else {
        // std::cout << "-----------------------" << std::endl;
        return std::
            move(  // XXX 使用std::move给返回值，调用了vector<T>的移动构造函数
                top._nested_list);  // BUG
                                    // copy给返回值，然后又copy给main中的变量
      }
    } else if (c == ',') {
      if (temp.empty()) continue;
      auto& top = sta.top();
      top._nested_list.emplace_back(
          atoi(temp.c_str()));  // BUG "]," parse as null nestedInteger
      temp.clear();
    } else {
      temp += c;
    }
  }
  return std::vector<NestedInteger>();
}

#endif  // NESTED_INTEGER_HPP