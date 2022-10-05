/**
 * @file 811.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-05
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    unordered_map<string, int> map;
    for (auto &domain : cpdomains) {
      int i;
      int rep = 0;
      int n = static_cast<int>(domain.size());
      for (i = 0; i < n; ++i) {
        if (domain[i] == ' ') break;
        rep *= 10;
        rep += domain[i] - '0';
      }
      ++i;
      map[domain.substr(i, n - i + 1)] += rep;
      i = domain.find_first_of('.', i);
      ++i;
      map[domain.substr(i, n - i + 1)] += rep;
      i = domain.find_first_of('.', i);
      if (i >= 0) map[domain.substr(i + 1, n - i + 1)] += rep;
    }
    vector<string> result;
    result.reserve(map.size());
    for (auto &res : map) {
      result.emplace_back(to_string(res.second) + " " + res.first);
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  vector<string> cpdomains{"900 google.mail.com", "50 yahoo.com",
                           "1 intel.mail.com", "5 wiki.org"};
  auto answer = sol.subdomainVisits(cpdomains);
  for (auto &str : answer) {
    std::cout << str << std::endl;
  }
  return 0;
}
