/**
 * @file 1137.cpp
 * @brief 第 N 个泰波那契数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-29
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int tribonacci(int n)
    {
        if (not n)
            return 0;
        vector<int> t(n + 1);
        if (n >= 3)
            t[1] = t[2] = 1;
        else
            return 1;
        for (int i = 3; i <= n; ++i)
        {
            t[i] = t[i - 3] + t[i - 2] + t[i - 1];
        }
        return t[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    std::cout << ans.tribonacci(36) << std::endl;
    return 0;
}
