/**
 * @file 62.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-09
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m < n)
            swap(m, n);
        vector<int> temp(m);
        temp[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                // temp[i][j] = temp[i - 1][j] + temp[i][j - 1];
                temp[j] += temp[j - 1];
            }
        }
        return temp[m - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int m, n;
    while (cin >> m >> n)
    {
        std::cout << ans.uniquePaths(m, n) << std::endl;
    }
    return 0;
}
