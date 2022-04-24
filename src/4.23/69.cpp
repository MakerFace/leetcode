/**
 * @file 69.cpp
 * @brief 平方根
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
     * @brief 暴力法
    int mySqrt(int x)
    {
        int result = 0;
        while (result < 46340 && result * result < x)
        {
            ++result;
        }
        if (result * result <= x)
        {
            return result;
        }
        return result - 1;
    }
     */
    /**
     * @brief 牛顿迭代法求解
     */
    int mySqrt(int x)
    {
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    cin >> n;
    std::cout << s.mySqrt(n) << std::endl;
    return 0;
}
