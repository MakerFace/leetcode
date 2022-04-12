/**
 * @file 357.cpp
 * @brief 各位数字都不同的数字个数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-11
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 设一个数字有n位
 * 第一位是1-9种共9个数，第二位是0-9种但不同于第一位，所以是9个数，第三位是0-9但不同1，2位，因此是8个数
 * 以此类推，f(n)=9*9*8*...*(9-k+2)
 * F(n) = f(n) + f(n - 1)
 */
class Solution {
    int coefficient[9] = {9, 9, 8, 7, 6, 5, 4, 3, 2};
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        int m = 1;
        for (size_t i = 0; i < n; i++)
        {
            m *= coefficient[i];
        }
        return countNumbersWithUniqueDigits(n-1) + m;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    cin >> n;
    auto res = s.countNumbersWithUniqueDigits(n);
    std::cout << res << std::endl;
    return 0;
}
