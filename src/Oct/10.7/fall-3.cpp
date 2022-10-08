/**
 * @file fall-3.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-07
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
  vector<int> count[100001];

 public:
  int beautifulBouquet(vector<int>& flowers, int cnt) {
    long long ans = 0;
    for (auto f : flowers) {
      
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> flowers{1, 2, 3, 2};
  int cnt;
  cin >> cnt;
  Solution sol;
  std::cout << sol.beautifulBouquet(flowers, cnt) << std::endl;
  return 0;
}
