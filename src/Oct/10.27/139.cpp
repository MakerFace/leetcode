/**
 * @file 139.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-27
 */
#include <fstream>
#include <ios>
#include <unordered_set>
#include <vector>

#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> word_set(wordDict.begin(), wordDict.end());
    int n = static_cast<int>(s.size());
    vector<int> dp(n + 1);
    dp[0] = 1;
    std::cout << wordDict << std::endl;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {  // 遍历物品？？
        string word = s.substr(j, i - j);
        if (word_set.count(word) != 0 and dp[j]) {
          dp[i] = 1;
        }
      }
    }
    return dp[n];
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.27/139.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    s = buf;
    in.getline(buf, MAX_LINE_SIZE);
    auto wordDict = string2vector<string>(buf);
    auto ans = sol.wordBreak(s, wordDict);
    std::cout << boolalpha << ans << std::endl;
  }
  return 0;
}
