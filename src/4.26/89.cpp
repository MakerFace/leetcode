/**
 * @file 89.cpp
 * @brief 格雷编码
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-26
 */
#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result(pow(2, n));
        result[0] = 0;
        result[1] = 1;
        int m = 2;
        for (int i = 1; i < n; ++i)
        {
            for (int j = m - 1, k = m; j >= 0; --j, ++k)
            {
                result[k] = result[j] | (1 << i);
            }
            m *= 2;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int n;
    while (cin >> n)
    {
        auto res = ans.grayCode(n);
        println_vector(res);
        std::cout << std::endl;
    }
    return 0;
}
