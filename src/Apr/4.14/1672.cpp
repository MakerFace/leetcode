/**
 * @file 1672.cpp
 * @brief 最富有客户的资产总量
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-14
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int max = 0, sum;
        for (size_t i = 0; i < accounts.size(); ++i)
        {
            sum = 0;
            for (size_t j = 0; j < accounts[i].size(); ++j)
            {
                sum += accounts[i][j];
            }
            if (max < sum)
            {
                max = sum;
            }
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> accounts = {{2,8,7},{7,1,3},{1,9,5}};
    auto res = s.maximumWealth(accounts);
    std::cout << res << std::endl;
    return 0;
}
