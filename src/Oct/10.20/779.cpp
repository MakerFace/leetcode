/**
 * @file 779.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-20
 */
#include <bits/stdc++.h>
#include <cstdlib>

#include "common/utils.hpp"

using namespace std;

class Solution {
public:
  int kthGrammar(int n, int k) {
    if (n == 1)
      return 0;
    auto temp = pow(2, n - 2);
    if (k > temp) {
      return not kthGrammar(n - 1, k - temp);
    } else {
      return kthGrammar(n - 1, k);
    }
  }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.20/779.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto k = atoi(buf);
    auto ans = sol.kthGrammar(n, k);
    std::cout << ans << std::endl;
  }
  return 0;
}
