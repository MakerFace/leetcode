/**
 * @file 857.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-11
 */
#include <bits/stdc++.h>

#include "common/utils.hpp"
using namespace std;

class Solution {
 public:
  /**
   * @brief 优先级队列（最大堆k-1）个数，每次弹出质量最高的。
   * total_cost = sum_i^k wage_i/quality_i*total_quality
   */
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n = quality.size();
    vector<int> idx(n, 0);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int& a, int& b) { // 使用索引数组对两个数组排序
      return quality[a] * wage[b] > quality[b] * wage[a];
    });
    double res = 1e9;
    double totalq = 0;
    priority_queue<int, vector<int>, less<int>> q;
    for (int i = 0; i < k - 1; i++) { // 添加top k-1个值
      totalq += quality[idx[i]];
      q.push(quality[idx[i]]);
    }
    for (int i = k - 1; i < n; i++) {
      int index = idx[i];
      totalq += quality[index];
      q.push(quality[index]); // 每次push一个值进去
      double totalc = ((double)wage[index] / quality[index]) * totalq;
      res = min(res, totalc);
      totalq -= q.top(); // pop一个最大值
      q.pop();
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> quality{3,1,10,10,1}, wage{4,8,2,2,7};
  int k = 3;
  Solution sol;
  std::cout << sol.mincostToHireWorkers(quality, wage, k) << std::endl;
  return 0;
}
