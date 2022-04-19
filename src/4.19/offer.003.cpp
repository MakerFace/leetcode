/**
 * @file offer.003.cpp
 * @brief 前 n 个数字二进制中 1 的个数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-19
 */
#include <bits/stdc++.h>
#include <common/utils.hpp>

using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1, 0);
        for (int i = 0; i <= n; ++i)
        {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.countBits(10);
    print_vector(res);
    return 0;
}