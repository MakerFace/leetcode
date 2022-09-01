/**
 * @file 6162.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-08-28
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int m = 0;
    int p = 0;
    int g = 0;
    for (size_t i = 0; i < garbage.size(); ++i) {
      for (auto& c : garbage[i]) {
        switch (c) {
          case 'M':
            ++m;
            break;
          case 'P':
            ++p;
            break;
          case 'G':
            ++g;
            break;
        }
      }
      if (i >= travel.size()) continue;
      m += travel[i];
      p += travel[i];
      g += travel[i];
    }
    return m + p + g;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<string> garbage({"G", "P", "GP", "GG"});
  vector<int> travel({2, 4, 3});
  cout << sol.garbageCollection(garbage, travel) << endl;
  return 0;
}
