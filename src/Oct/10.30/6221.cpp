/**
 * @file 6221.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-30
 */
#include <climits>
#include <fstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "common/Vector.hpp"
using namespace std;

class Solution {
 public:
  vector<vector<string>> mostPopularCreator(vector<string>& creators,
                                            vector<string>& ids,
                                            vector<int>& views) {
    vector<vector<string>> ans;
    unordered_map<string, long long> cvmap;
    unordered_map<string, pair<long long, string>> cimap;
    int i = 0;
    long long maxv = LONG_LONG_MIN;
    for (auto&& s : creators) {
      cvmap[s] += views[i];
      maxv = max(cvmap[s], maxv);
      if (views[i] == cimap[s].first) {
        if (cimap[s].second == "" or cimap[s].second >= ids[i])
          cimap[s].second = ids[i];
      } else if (views[i] > cimap[s].first) {
        cimap[s].first = views[i];
        cimap[s].second = ids[i];
      }
      ++i;
    }
    for (auto&& m : cvmap) {
      if (m.second == maxv) {
        ans.emplace_back(vector<string>{m.first, cimap[m.first].second});
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.30/6221.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto creators = string2vector<string>(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto ids = string2vector<string>(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto views = string2vector(buf);
    auto ans = sol.mostPopularCreator(creators, ids, views);
    std::cout << ans << std::endl;
  }
  return 0;
}
