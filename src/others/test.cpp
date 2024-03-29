// #include <algorithm>
// #include <cfloat>
// #include <chrono>
// #include <climits>
// #include <iomanip>
#include <iostream>
#include <string>
// #include <map>
// #include <numeric>
// #include <stack>
// #include <vector>

// #include "common/utils.hpp"
using namespace std;

// class test {
// private:
//   int *value;

// public:
//   test(int i) {
//     value = new int(i);
//     std::cout << "Constructor" << *value << std::endl;
//     ++*value;
//   }
//   test(const test &t) {
//     value = new int(*t.value);
//     std::cout << "copy constructor" << *value << std::endl;
//     ++*value;
//   }
//   test(test &&t) {
//     value = t.value;
//     t.value = nullptr;
//     std::cout << "move constructor" << *value << std::endl;
//     ++*value;
//   }
//   ~test() {
//     if (value != nullptr)
//       delete value;
//   }
// };

// static test getTest() {
//   static int i = 1;
//   test t(i);
//   return t;
// }

// struct alignas(4) s
// // #pragma pack(4)
// // struct s
// {
//   uint8_t a;
//   uint16_t b;
//   uint8_t c;
// };
// struct foo {
//   int i;
//   double d;
//   char c;
// };

// struct alignas(16) foo_n {
//   int i;
//   float d;
//   char c;
// };

// class Base {
//  public:
//   Base() {}
//   int get(int x = 2) { return x; };
// };

// struct TestS {
//   int a, b;
// };

//  public:
//   Test() {}
//   Test(int _x) {}
//   explicit operator int() { return 1; }
//   int get(int x = 3) {
//     return x;
//   }  // 默认参数无效，使用的仍是父类的默认参数（缺省参数静态绑定导致）
// };
__attribute__((constructor)) void before() { printf("before main\n"); }

// public:
//   Test() {}
//   Test(int _x) {}
//   explicit operator int() { return 1; }
//   virtual int get(int x = 3) {
//     return x;
//   } // 默认参数无效，使用的仍是父类的默认参数（缺省参数静态绑定导致）
// };
// __attribute__((constructor)) void before() { printf("before main\n"); }

// class Person {
// public:
//   template <typename T,
//             typename = typename std::enable_if<
//                 !std::is_base_of<Person, typename std::decay<T>::type>::value
//                 && !std::is_integral<
//                     typename std::remove_reference<T>::type>::value>::type>
//   explicit Person(T &&n) : name(std::forward<T>(n)) {
//     std::cout << "forward" << std::endl;
//   }

//   explicit Person() { std::cout << "null" << std::endl; }

//   explicit Person(int idx) { std::cout << "int" << std::endl; }

//   explicit Person(const Person &rhs) : name(rhs.name) {
//     std::cout << "const Person&" << std::endl;
//   }

//   explicit Person(Person &&rhs) : name(std::forward<std::string>(rhs.name)) {
//     std::cout << "Person&&" << std::endl;
//   }

// private:
//   std::string name;
// };
// Person p1;
// Person p2("string");
// Person p3(16);
// Person p4(p2); // 复制构造函数

// int before(int x) {
//   printf("before main %d\n", x);
//   return x;
// }
// int a = before(2);
// int b = []() -> int {
//   std::cout << "before main 3\n";
//   return 3;
// }();

__attribute__((destructor)) void after() { printf("after main\n"); }
// constexpr int getFive() { return 5; }
// const int getFive(int x) { return x; }

// template <class PQ> class Extractable : public PQ {
// public:
//   using PQ::PQ;
//   using typename PQ::container_type;
//   container_type &&container() && { return std::move(this->c); }
//   const container_type &container() const & { return this->c; }
//   container_type &container() & { return this->c; }

//   container_type sorted_container() && {
//     std::sort_heap(this->c.begin(), this->c.end(), this->comp);
//     return std::move(this->c);
//   }
// };

class A {
public:
};

int main(int argc, char const *argv[]) {
  //   vector<int> heap;
  //   // priority_queue<int> pq;
  // Extractable<std::priority_queue<int, std::vector<int>, std::greater<int>>>
  // pq; default_random_engine default_random; for (int i = 0; i < 10; i++) {
  //   heap.push_back(default_random() % 100);
  //   pq.emplace(heap.back());
  // }

  // heap = std::move(pq).sorted_container();
  //   println_vector(heap);
  //   return 0;
  // int n = 16;
  // cin >> n;
  // vector<int> nums(n);
  // default_random_engine dre(time(0));
  // generate(nums.begin(), nums.end(), [&]() { return n--; });
  // println_vector(nums);

  // auto len = static_cast<int>(nums.size());

  // auto begin = nums.begin();
  // auto middle = begin, end = begin;
  // for (int n = 2; n <= len; n *= 2) {
  //   begin = nums.begin();
  //   middle = begin + n / 2;
  //   end = begin + n;
  //   while (end <= nums.end()) {
  //     inplace_merge(begin, middle, end);
  //     begin = end;
  //     middle = begin + n / 2;
  //     end = begin + n;
  //   }
  // }
  // if (begin < nums.end()) {
  //   inplace_merge(nums.begin(), begin, nums.end());
  // }

  // println_vector(nums);
  // Base* base = new Test();
  // Test* test = dynamic_cast<Test*>(base);
  // std::cout << test->get() << std::endl;
  std::cout << "main function" << std::endl;
  return 0;
}
