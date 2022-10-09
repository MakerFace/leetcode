/**
 * @file 6202.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-09
 */
#include <bits/stdc++.h>

using namespace std;

// 作者：TsReaper
// 链接：https://leetcode.cn/circle/discuss/YNdXJT/view/AK1rhT/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
 public:
  string robotWithString(string s) {
    int n = s.size();
    vector<char> f(n + 1);
    f[n] = 'z' + 1;
    // 后面串的最小字符
    for (int i = n - 1; i >= 0; i--) f[i] = min(f[i + 1], s[i]);

    string ans;
    stack<char> stk;
    for (int i = 0; i < n; i++) {
      stk.push(s[i]);
      while (!stk.empty() && stk.top() <= f[i + 1])
        ans.push_back(stk.top()), stk.pop();
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string s = "bydizfve";

  std::cout << sol.robotWithString(s) << std::endl;

  return 0;
}
