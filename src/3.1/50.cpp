/**
 * @file 50.cpp
 * @brief pow
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-03-01
 */
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * @brief 快速幂法
 * n的二进制数位的x^2^i次幂之和
 * n = 10(1010)
 */
class Solution
{
public:
    double myPow(double x, int n)
    {
        double res = 1;
        if (n < 0)
        {
            if (n == -2147483648)
            {
                res = myPow(1 / x, 2147483647);
                return res * 1 / x;
            }
            return myPow(1 / x, -n);
        }
        double temp = x;
        while (n)
        {
            if (n % 2)
            {
                res *= temp;
            }
            temp *= temp;
            n /= 2;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    double x;
    int n;
    std::cin >> x >> n;
    auto res = s.myPow(x, n);
    std::cout << res << std::endl;
    return 0;
}
