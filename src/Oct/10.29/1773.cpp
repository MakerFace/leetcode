/**
 * @file 1773.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-29
 */
#include <fstream>
#include <string>

#include "common/Matrix.hpp"
#include "common/common.hpp"

using namespace std;

class Solution {
 public:
  int countMatches(vector<vector<string>>& items, string ruleKey,
                   string ruleValue) {
    int ans = 0;
    int idx = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
    for (auto &item : items) {
      ans += item[idx] == ruleValue;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.29/1773.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto items = string2matrix<string>(buf);
    std::cout << items << std::endl;
    string ruleKey, ruleValue;
    std::getline(in, ruleKey);
    std::getline(in, ruleValue);
    auto ans = sol.countMatches(items, trim(ruleKey, '"'), trim(ruleValue, '"'));
    std::cout << ans << std::endl;
  }
  return 0;
}
