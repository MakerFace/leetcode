#include <vector>

using namespace std;

template <typename Iterator>
void my_next_permutation(Iterator first, Iterator end) {
  if (first == end) {  // 空集合
    return;
  }
  auto i = first;
  ++i;
  if (i == end) {  // 只有一个元素
    return;
  }

  i = end;
  --i;
  for (;;) {
    Iterator ii = i;  // i的下一个元素
    --i;
    if (*i < *ii) {  // 相邻元素顺序
      auto j = end;
      while (*i >= *(--j)) {  // 从后边找到第一个小于i的
      }
      swap(*i, *j);      // 交换i, j
      reverse(ii, end);  // i后边逆序
      return;
    }
    if (i == first) {  // 如果全逆序，就回到第一个序列
      reverse(first, end);
      return;
    }
  }
}