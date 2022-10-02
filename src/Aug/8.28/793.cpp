/**
 * @file 793.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-01
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int zeta(long x) {
        int res = 0;
        while (x) {
            res += x / 5;
            x /= 5;
        }
        return res;
    }

    long long help(int k) {
        long long r = 5LL * k;
        long long l = 0;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (zeta(mid) < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r + 1;
    }

    int preimageSizeFZF(int k) {
        return help(k + 1) - help(k);
    }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  int k;
  while (cin >> k) {
    std::cout << sol.preimageSizeFZF(k) << std::endl;
  }

  return 0;
}
