#ifndef UTILS_HPP
#define UTILS_HPP

#include <bits/stdc++.h>

template <typename T>
inline void print_vector(std::vector<T> v) {
  size_t i = 0;
  std::cout << "[";
  if (!v.empty()) std::cout << v[i++];
  for (; i < v.size(); ++i) {
    std::cout << "," << v[i];
  }
  std::cout << "]";
}

template <typename T>
inline void println_vector(std::vector<T> v) {
  print_vector(v);
  std::cout << std::endl;
}

#endif // UTILS_HPP
