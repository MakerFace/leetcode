/**
 * @file test2.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-15
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"

using namespace std;

class Solution {
 public:
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    for (int i = 0; i < 32; i++) {
      if ((1 << i) & n) table.emplace_back(1 << i);
    }
    int m = static_cast<int>(queries.size());
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
      ans[i] = compute(queries[i][0], queries[i][1]);
    }
    return ans;
  }

 private:
  long long compute(int left, int right) {
    if (left == right) return table[right];
    auto key = idx2key(left, right);
    auto res = map.find(key);
    if (res != map.end()) return res->second;
    map[key] = table[left] * compute(left + 1, right) % 1000000007;
    return map[key];
  }

  int idx2key(int i, int j) { return i * 100 + j; }

 private:
  vector<long long> table;
  unordered_map<int, long long> map;
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.15/test2.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto n = atoi(buf);
    in.getline(buf, MAX_LINE_SIZE);
    s = buf;
    auto queries = string2matrix<int>(s);
    auto ans = sol.productQueries(n, queries);
    std::cout << ans << std::endl;
  }
  return 0;
}
