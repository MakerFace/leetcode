/**
 * @file 467.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-25
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
 /**
  * @brief 以dp[\alpha]结尾的字符串数量
  * 例如，abcd，以d结尾的串有abcd, bcd, cd, d四个
  * @param  p                My Param doc
  * @return int 
  */
  int findSubstringInWraproundString(string p) {
    array<int, 26> dp{0};
    int k = 0;
    for (size_t i = 0; i < p.size(); ++i) {
      if (i and (p[i] - p[i - 1] + 26) % 26 == 1) {
        ++k;
      } else {
        k = 1;
      }
      dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
    }
    return accumulate(dp.begin(), dp.end(), 0);
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  string p;
  while (cin >> p) {
    std::cout << ans.findSubstringInWraproundString(p) << std::endl;
  }
  return 0;
}
