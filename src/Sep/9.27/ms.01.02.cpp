/**
 * @file ms.01.02.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-27
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool CheckPermutation(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    int n = s1.size();
    unordered_map<char, int> umap1;
    unordered_map<char, int> umap2;
    for (int i = 0; i < n; ++i) {
      umap1[s1[i]]++;
      umap2[s2[i]]++;
    }
    for (auto &um : umap1) {
      if (um.second != umap2[um.first]) return false;
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
