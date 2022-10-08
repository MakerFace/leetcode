#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <bits/stdc++.h>

#include "common/utils.hpp"

template <typename T>
using Matrix = std::vector<std::vector<T>>;

template <typename T>
void print_matrix(const Matrix<T> &matrix) {
  std::cout << "[";
  for (auto var : matrix) {
    print_vector(var);
    std::cout << ",";
  }
  if (not matrix.empty()) std::cout << "\b";
  std::cout << "]";
}

template <typename T>
void println_matrix(const Matrix<T> &matrix) {
  print_matrix(matrix);
  std::cout << std::endl;
}

#endif // MATRIX_HPP
