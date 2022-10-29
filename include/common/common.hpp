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

/**
 * @brief 证同
 */
template <typename T>
struct identity {
  typedef identity type;

  identity() {}

  T operator()(const T& str) { return str; }
};

/**
 * @brief trim left white space
 * @param  s                the string to trim space
 * @param  white            white space
 * @return std::string
 */
std::string ltrim(const std::string& s, char white) {
  size_t start = s.find_first_not_of(white);
  return (start == std::string::npos) ? "" : s.substr(start);
}

/**
 * @brief trim right white space
 * @param  s                the string to trim space
 * @param  white            white space
 * @return std::string
 */
std::string rtrim(const std::string& s, char white) {
  size_t end = s.find_last_not_of(white);
  return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

/**
 * @brief trim left and right white space
 * @param  s                the string to trim space
 * @param  white            white space, default is space(32)
 * @return std::string 
 */
std::string trim(const std::string& s, char white = ' ') {
  return rtrim(ltrim(s, white), white);
}

#endif  // COMMON_HPP