#include "complex.hh"

#include <iostream>

namespace chen {
void print(const complex& c, int) {
  std::cout << "print friend func" << std::endl;
}
}  // namespace chen

std::ostream& operator<<(std::ostream& os, const chen::complex& c) {
  return os << "(" << c.x_ << "," << c.y_ << ")";
}
