/**
 * @file 386.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-18
 */

#include <bits/stdc++.h>
#include <common/utils.hpp>
using namespace std;

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> res(n, 0);
        int number = 1;
        for (int cur = 0; cur < n; ++cur)
        {
            res[cur] = number;
            if (number * 10 <= n)
            {
                number *= 10;
            }
            else
            {
                while ((number % 10 == 9) || (number + 1 > n))
                {
                    number /= 10;
                }
                ++number;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.lexicalOrder(1000);
    print_vector(res);
    return 0;
}
