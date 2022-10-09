#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <ostream>
#include <vector>

template <typename T>
inline void print_vector(const std::vector<T>& v) {
  size_t i = 0;
  std::cout << "[";
  if (!v.empty()) std::cout << v[i++];
  for (; i < v.size(); ++i) {
    std::cout << "," << v[i];
  }
  std::cout << "]";
}

template <typename T>
inline void println_vector(const std::vector<T>& v) {
  print_vector(v);
  std::cout << std::endl;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
  size_t i = 0;
  out << "[";
  if (!v.empty()) std::cout << v[i++];
  for (; i < v.size(); ++i) {
    out << "," << v[i];
  }
  out << "]";
  return out;
}

#endif  // VECTOR_HPP