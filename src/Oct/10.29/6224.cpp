/**
 * @file 6224.cpp
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
  string oddString(vector<string>& words) {
    string a = get_diff(words[0]);
    string b = get_diff(words[1]);
    string c = get_diff(words[2]);
    string judge;
    if (a == b) {
      judge = a;
    } else if (a == c) {
      judge = a;
    } else {
      judge = b;
    }

    for (size_t i = 0; i < words.size(); ++i) {
      auto temp = get_diff(words[i]);
      if (temp != judge) {
        return words[i];
      }
    }
    return "";
  }

 private:
  string get_diff(const string& str) {
    string ans;
    for (size_t i = 0; i + 1 < str.size(); ++i) {
      ans.push_back(str[i + 1] - str[0] + 'a');
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.29/6224.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto words = string2vector<string>(buf);
    auto ans = sol.oddString(words);
    std::cout << ans << std::endl;
  }
  return 0;
}
