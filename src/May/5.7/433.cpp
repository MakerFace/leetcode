/**
 * @file 433.cpp
 * @brief 最小基因变化
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-07
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  unordered_map<string, bool> map;

 public:
  int minMutation(string start, string end, vector<string> &bank) {
    if (bank.empty()) return -1;
    int result = 0;
    auto iter = find(bank.begin(), bank.end(), start);
    if (iter == bank.end())
      bank.insert(bank.begin(), 1, start);
    else
      swap(*(bank.begin()), *iter);
    iter = find(bank.begin(), bank.end(), end);
    if (iter == bank.end()) return -1;
    swap(*iter, *(bank.end() - 1));
    int n = bank.size();

    // 构造相邻图
    vector<vector<bool>> graph(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        graph[i].push_back(find_differences(bank[i], bank[j]));
      }
    }

    // BFS
    queue<int> q;
    int col = 0;
    q.push(col);
    while (not q.empty()) {
      int cur_size = q.size();
      for (int j = 0; j < cur_size; ++j) {
        col = q.front();
        q.pop();
        if (bank[col] == end) return result;
        for (size_t i = 0; i < graph[col].size(); ++i) {
          if (graph[col][i]) {
            q.push(i);
            graph[col][i] = false;
            graph[i][col] = false;
          }
        }
      }
      ++result;
    }
    return -1;
  }

 private:
  bool find_differences(string start, string end) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
      if (start[i] != end[i]) ++count;
    }
    return count == 1;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  string start = "AAAAAAAA";
  string end = "CCCCCCCC";
  vector<string> bank = {"AAAAAAAA", "AAAAAAAC", "AAAAAACC",
                         "AAAAACCC", "AAAACCCC", "AACACCCC",
                         "ACCACCCC", "ACCCCCCC", "CCCCCCCA"};
  std::cout << ans.minMutation(start, end, bank) << std::endl;
  return 0;
}
