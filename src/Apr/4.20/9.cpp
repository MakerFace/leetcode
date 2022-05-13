/**
 * @file 9.cpp
 * @brief 回文数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-20
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int t = 0;
        int p = x;
        while (p)
        {
            t *= 10;
            t += p % 10;
            p /= 10;
        }
        return x == t;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << boolalpha << s.isPalindrome(120) << std::endl;
    return 0;
}
