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

template <typename T = int>
Matrix<T> string2matrix(const std::string& str) {
  Matrix<T> ans;
  std::vector<T> temp;
  for (size_t i = 1; i < str.size() - 1; ++i) {
    if (str[i] == '[') continue;
    int num = 0;
    while (str[i] >= '0' and str[i] <= '9') {
      num *= 10;
      num += str[i++] - '0';
    }
    temp.push_back(num);
    if (str[i] == ']') ++i, ans.emplace_back(std::move(temp));
  }
  return ans;
}

template <>
Matrix<char> string2matrix(const std::string& str) {
  Matrix<char> ans;
  std::string::const_iterator first, last;
  std::vector<char> temp;
  for (size_t i = 1; i < str.size() - 1; ++i) {
    if (std::isalpha(str[i]))
      temp.push_back(str[i]);
    else if (str[i] == ']')
      ans.emplace_back(std::move(temp));
  }
  return ans;
}

#endif  // MATRIX_HPP
