#ifndef COMPLEX_HH
#define COMPLEX_HH
#include <iostream>

namespace chen {
class complex;
}

std::ostream& operator<<(std::ostream& os, const chen::complex& c);

namespace chen {

class complex {
 public:
  complex() : x_(0), y_(0) {}
  complex(int x, int y) : x_(x), y_(y) {}

  complex operator~() const { return complex(x_, -y_); }

  complex operator*(const complex& rv) const {
    return complex(x_ * rv.x_ - y_ * rv.y_, x_ * rv.y_ + y_ * rv.x_);
  }

  friend std::ostream& ::operator<<(std::ostream& os, const complex& c);

 private:
  int x_, y_;
};

}  // namespace chen

#endif  // COMPLEX_HH