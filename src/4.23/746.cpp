/**
 * @file 746.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-23
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    /**
     * @brief dp
     */
    int minCostClimbingStairs(vector<int> &cost)
    {
        int dp[cost.size()];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); ++i)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]); // i-1迈一步，i-2迈两步
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::cout << s.minCostClimbingStairs(cost) << std::endl;
    return 0;
}