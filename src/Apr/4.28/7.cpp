/**
 * @file 7.cpp
 * @brief 整数反转
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-28
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        if (x == INT_MIN)
            return 0;
        int result = 0;
        bool negative = false;
        if (x < 0)
        {
            x = -x;
            negative = true;
        }
        while (x)
        {
            if (result > 214748364)
            {
                return 0;
            }
            else if (result == 214748364 && x % 10 > 7)
            {
                return 0;
            }
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        if (negative)
            result = -result;
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    std::cout << ans.reverse(-2147483647) << std::endl;
    return 0;
}
