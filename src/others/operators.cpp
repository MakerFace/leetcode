#include "Complex/complex.hh"
#include <iostream>

using namespace std;

namespace test {
void print(const chen::complex& c) { std::cout << "test" << std::endl; }
}  // namespace test

int main() {
  chen::complex c(1, 2);
  auto b = ~c;
  std::cout << b * c << std::endl;
  test::print(c);
  // print(c, 1);
}