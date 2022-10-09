#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <bits/stdc++.h>

#include "common/Vector.hpp"

template <typename T>
using Matrix = std::vector<std::vector<T>>;

template <typename T>
void print_matrix(const Matrix<T>& matrix, std::ostream& out = std::cout) {
  out << "[";
  for (auto var : matrix) {
    print_vector(var);
    out << ",";
  }
  if (not matrix.empty()) std::cout << "\b";
  out << "]";
}

template <typename T>
void println_matrix(const Matrix<T>& matrix) {
  print_matrix(matrix);
  std::cout << std::endl;
}

template <typename T>
std::istream& operator<<(std::istream& out, const Matrix<T>& matrix) {
  print_matrix(matrix, out);
  return out;
}

#endif  // MATRIX_HPP
