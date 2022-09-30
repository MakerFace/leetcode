/**
 * @file 1652.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-24
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    vector<int> result(code.size(), 0);
    if (not k) return result;
    int n = static_cast<int>(code.size());
    int count = 0;
    if (k > 0) {
      for (int i = 0; i < k; i++) count += code[i];
      for (int i = 0; i < n; i++) {
        count = count - code[i] + code[(k + i) % n];
        result[i] = count;
      }
    } else {
      for (int i = 0; i > k; --i) count += code[(n + i) % n];
      for (int i = 0; i > -n; --i) {
        count = count - code[(n + i) % n] + code[(2 * n + k + i) % n];
        result[(n + i) % n] = count;
      }
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> code{5, 7, 1, 4};
  int k = -1;
  Solution sol;
  auto ans = sol.decrypt(code, k);
  println_vector(ans);
  return 0;
}
