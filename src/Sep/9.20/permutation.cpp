/**
 * @file permutation.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-20
 */

#include <bits/stdc++.h>

using namespace std;

void getperm(int a[], int begin, int end) {
  if (begin == end) {
    for (int i = 0; i < end; i++) {
      cout << a[i] << ' ';
    }
    std::cout << std::endl;
    return;
  }
  for (int i = begin; i < end; ++i) {
    swap(a[begin], a[i]);
    getperm(a, begin + 1, end);
    swap(a[begin], a[i]);
  }
}

int main(int argc, char const *argv[]) {
  int a[] = {1, 2, 3, 4};
  getperm(a, 0, 4);
  return 0;
}
