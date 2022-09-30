#include <cfloat>
#include <climits>
#include <iomanip>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class test {
 private:
  int *value;

 public:
  test(int i) {
    value = new int(i);
    std::cout << "Constructor" << *value << std::endl;
    ++*value;
  }
  test(const test &t) {
    value = new int(*t.value);
    std::cout << "copy constructor" << *value << std::endl;
    ++*value;
  }
  test(test &&t) {
    value = t.value;
    t.value = nullptr;
    std::cout << "move constructor" << *value << std::endl;
    ++*value;
  }
  ~test() {
    if (value != nullptr) delete value;
  }
};

static test getTest() {
  static int i = 1;
  test t(i);
  return t;
}

struct alignas(4) s
// #pragma pack(4)
// struct s
{
  uint8_t a;
  uint16_t b;
  uint8_t c;
};
struct foo {
  int i;
  double d;
  char c;
};

struct alignas(16) foo_n {
  int i;
  float d;
  char c;
};

class Base {
 public:
  Base() {}
  virtual int get(int x = 2) = 0;
};

class Test : public Base {
 private:
  // int x;
  // int y;

 public:
  Test() {}
  Test(int _x) {}
  explicit operator int() { return 1; }
  virtual int get(int x = 3) {
    return x;
  }  // 默认参数无效，使用的仍是父类的默认参数（缺省参数静态绑定导致）
};
__attribute__((constructor)) void before() { printf("before main\n"); }

class Person {
 public:
  template <typename T,
            typename = typename std::enable_if<
                !std::is_base_of<Person, typename std::decay<T>::type>::value &&
                !std::is_integral<
                    typename std::remove_reference<T>::type>::value>::type>
  explicit Person(T &&n) : name(std::forward<T>(n)) {
    std::cout << "forward" << std::endl;
  }

  explicit Person() { std::cout << "null" << std::endl; }

  explicit Person(int idx) { std::cout << "int" << std::endl; }

  explicit Person(const Person &rhs) : name(rhs.name) {
    std::cout << "const Person&" << std::endl;
  }

  explicit Person(Person &&rhs) : name(std::forward<std::string>(rhs.name)) {
    std::cout << "Person&&" << std::endl;
  }

 private:
  std::string name;
};
Person p1;
Person p2("string");
Person p3(16);
Person p4(p2);  // 复制构造函数

int before(int x) {
  printf("before main %d\n", x);
  return x;
}
int a = before(2);
int b = []() -> int {
  std::cout << "before main 3\n";
  return 3;
}();

__attribute__((destructor)) void after() { printf("after main\n"); }
constexpr int getFive() { return 5; }
const int getFive(int x) { return x; }

int main(int argc, char const *argv[]) {
  std::vector<int> test;
  cout << test.size() << endl;
  return 0;
}
