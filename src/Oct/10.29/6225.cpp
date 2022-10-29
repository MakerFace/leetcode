/**
 * @file 6225.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-29
 */
#include <bits/stdc++.h>

#include <cstddef>
#include <unordered_map>
#include <vector>

#include "common/Vector.hpp"
using namespace std;

class Solution {
 public:
  vector<string> twoEditWords(vector<string>& queries,
                              vector<string>& dictionary) {
    vector<string> ans;
    for (auto& q : queries) {
      for (auto& d : dictionary) {
        if (diff(q, d)) {
          ans.emplace_back(q);
          break;
        }
      }
    }
    return ans;
  }

 private:
  bool diff(const string& src, const string& desc) {
    int count = 0;
    for (size_t i = 0; i < src.size() and count <= 2; ++i) {
      count += src[i] != desc[i];
    }
    return count <= 2;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.29/6225.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto queries = string2vector<string>(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto dictionary = string2vector<string>(buf);
    auto ans = sol.twoEditWords(queries, dictionary);
    std::cout << ans << std::endl;
  }
  return 0;
}
