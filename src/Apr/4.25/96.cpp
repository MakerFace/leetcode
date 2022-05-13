/**
 * @file 96.cpp
 * @brief 不同的二叉搜索树
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-25
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        if (n >= 2)
            dp[2] = 2;
        for (int i = 3; i <= n; ++i) // 以i为根
        {
            for (int j = 1; j <= i; ++j)
            {
                if (j == 2 && i - j == 1)
                    dp[i] += 1;
                else if (j == 2)
                    dp[i] += dp[i - j];
                else if (i - j == 1)
                    dp[i] += dp[j - 1];
                else
                    dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int n;
    while (cin >> n)
        std::cout << ans.numTrees(n) << std::endl;
    return 0;
}
