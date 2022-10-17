#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <sstream>
#include <vector>

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
  static std::stringstream ss;
  Matrix<T> ans;
  ss.str(str.substr(2, str.size() - 3));
  ss.clear();
  std::string temp;
  std::string s;
  while (std::getline(ss, temp, '[')) {
    s = "[" + temp;
    if (s.back() == ',') s.pop_back();
    if (s.back() == ']')
      ans.emplace_back(std::move(string2vector<T>(s))), s.clear();
  }
  return ans;
}

#endif  // MATRIX_HPP
