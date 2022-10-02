/**
 * @file main.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-24
 */
#include <bits/stdc++.h>

#include <boost/type_index.hpp>
using namespace std;

template <typename T>
void f(T param) {
  using boost::typeindex::type_id_with_cvr;
  std::cout << "T =    " << type_id_with_cvr<T>().pretty_name() << std::endl;
  std::cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name()
            << std::endl;
}

class Widget {
 private:
  int x{0}, y{1};

 public:
  Widget() { std::cout << y << std::endl; }
  Widget(int x, int y) : x(x), y(y) {
    std::cout << x << ", " << y << std::endl;
  }
  Widget(int x, double y) : x(x) { std::cout << y << std::endl; }
  Widget(std::initializer_list<string> l) {
    auto it = l.begin();
    x = atoi(it->data());
    ++it;
    y = atoi(it->data());
    std::cout << "init list " << x << ", " << y << std::endl;
  }

 public:
  void operator()() { std::cout << "operator()" << std::endl; }
};

enum class Color { black, white, red };
template <typename E>
constexpr typename std::underlying_type<E>::type toUType(
    E enumerator) noexcept {
  return static_cast<typename std::underlying_type<E>::type>(enumerator);
}

int main(int argc, char const* argv[]) {
  const Widget& w1{};
  Widget w2{1, 2};
  Widget w3{1, 3.f};
  Widget w4{"1", "5"};
  using NoConstWidget = std::remove_const<decltype(w1)>::type;
  using NoRefWidget = std::remove_reference<decltype(w1)>::type;
  NoConstWidget t1 = Widget();
  NoRefWidget t2;
  f(t1);
  f(t2);
  std::cout << toUType(Color::white) << std::endl;
  priority_queue<int, vector<int>> q;
  vector<int> values(10, 0);
  iota(values.begin(), values.end(), 0);
  for (auto& v : values) {
    q.push(v);
  }
  while (not q.empty())
  {
    std::cout << q.top() << std::endl;
    q.pop();
  }
  
  return 0;
}
