/**
 * @file 131.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-25
 */
#include <bits/stdc++.h>

#include "common/Matrix.hpp"
using namespace std;

class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    for (size_t i = 0; i < s.size(); ++i) {
        
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  string s;
  while (cin >> s) {
    auto res = ans.partition(s);
    print_matrix(res);
  }
  return 0;
}
