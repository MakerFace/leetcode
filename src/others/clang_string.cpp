#include <iostream>
#include <string>

/**
 * @brief  clang 编译命令加入 -fno-limit-debug-info即可
 */
int main() {
  std::string str{"hello"};
  std::cout << str << std::endl;
  return 0;
}