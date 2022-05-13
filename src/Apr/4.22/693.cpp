/**
 * @file 693.cpp
 * @brief 交替位的二进制数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-22
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        bool res = n % 2;
        n /= 2;
        while (n)
        {
            if (!res != (n % 2))
            {
                return false;
            }
            res = n % 2;
            n /= 2;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    cin >> n;
    std::cout << boolalpha << s.hasAlternatingBits(n) << std::endl;
    return 0;
}
