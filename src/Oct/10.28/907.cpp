/**
 * @file 907.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-28
 */
#include <fstream>
#include <utility>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  /**
   * @brief 单调栈法，arr[i]左右各维护一个单调栈，
   * left非递增，right递增，如果arr[i]大于left.top
   * left
   * @param  arr              My Param doc
   * @return int
   */
  int sumSubarrayMins(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    vector<int> sta;
    sta.reserve(n);
    vector<int> left(n), right(n);
    for (int i = 0; i < n; ++i) {
      while (not sta.empty() and arr[i] <= arr[sta.back()]) {
        sta.pop_back();
      }
      left[i] = i - (sta.empty() ? -1 : sta.back());
      sta.emplace_back(i);
    }
    sta.clear();
    for (int i = n - 1; i >= 0; --i) {
      while (not sta.empty() and arr[i] < arr[sta.back()]) {
        sta.pop_back();
      }
      right[i] = (sta.empty() ? n : sta.back()) - i;
      sta.emplace_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = (ans + (long long)left[i] * right[i] * arr[i]) % 1000000007;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.28/907.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto arr = string2vector(buf);
    auto ans = sol.sumSubarrayMins(arr);
    std::cout << ans << std::endl;
  }
  return 0;
}
