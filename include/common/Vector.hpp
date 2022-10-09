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

template <typename T>
std::vector<T> string2vector(const std::string& str) {
  static std::stringstream ss;
  ss.str(str.substr(1, str.size() - 1));
  ss.clear();
  auto length = std::count_if(str.begin(), str.end(),
                              [](const char& c) { return c == ','; });
  std::vector<T> ans(length + 1);
  int i = 0;
  std::string temp;
  while (std::getline(ss, temp, ',')) ans[i++] = std::atoi(temp.c_str());
  return ans;
}

#endif  // VECTOR_HPP