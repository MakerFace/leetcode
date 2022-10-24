#ifndef COMMON_HPP
#define COMMON_HPP

#include <string>
#include <type_traits>

// BUG char is integral type
template <typename T>
struct str2int {
  typedef str2int type;
  T operator()(const std::string& str) { return std::atoi(str.c_str()); }
};

// FIXME template <
// typename T,
// std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr,
// std::enable_if_t<std::is_same_v<T, std::make_signed_t<T>> ||
// std::is_same_v<T, std::make_unsigned_t<T>>, std::nullptr_t> = nullptr
// >
template <typename T>
struct str2char {
  typedef str2char type;
  T operator()(const std::string& str) {
    if (str.size() == 3)
      return str[1];
    else
      return str[0];
  }
};

template <typename T>
struct identity {
  typedef identity type;

  identity() {}

  T operator()(const T& str) { return str.substr(1, str.size() - 2); }
};

#endif  // COMMON_HPP