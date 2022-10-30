#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

#include "common/common.hpp"

struct vector_hash {
  std::size_t operator()(std::vector<uint32_t> const &vec) const {
    std::size_t seed = vec.size();
    for (auto &i : vec) {
      seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

template <typename T>
inline void print_vector(const std::vector<T> &v) {
  size_t i = 0;
  std::cout << "[";
  if (!v.empty()) std::cout << v[i++];
  for (; i < v.size(); ++i) {
    std::cout << "," << v[i];
  }
  std::cout << "]";
}

template <typename T>
inline void println_vector(const std::vector<T> &v) {
  print_vector(v);
  std::cout << std::endl;
}

template <typename T>
inline std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  size_t i = 0;
  out << "[";
  if (!v.empty()) std::cout << v[i++];
  for (; i < v.size(); ++i) {
    out << "," << v[i];
  }
  out << "]";
  return out;
}

template <typename T = int>
std::vector<T> string2vector(const std::string &str) {
  static std::stringstream ss;
  using Opt = typename std::conditional<
      std::is_integral<T>::value,
      typename std::conditional<std::is_same<T, char>::value,
                                typename str2char<T>::type,
                                typename str2int<T>::type>::type,
      typename identity<T>::type>::type;
  Opt opt;
  ss.str(str.substr(1, str.size() - 2));
  ss.clear();
  std::vector<T> ans;
  std::string temp;
  while (std::getline(ss, temp, ',')) {
    temp = trim(trim(temp), '"');
    ans.emplace_back(opt(temp));
  }
  return ans;
}

#endif  // VECTOR_HPP