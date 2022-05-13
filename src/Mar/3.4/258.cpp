/**
 * @file 258.cpp
 * @brief 各位相加
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-03-04
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 从1-9, 10-18, ...每9个数循环，如果不是9的倍数，则直接返回N%9，否则返回9。
 * 因为9的倍数不能被模出来，所以要单独表示
 */
class Solution
{
public:
    int addDigits(int num)
    {
        if (num < 10)
        {
            return num;
        }
        if (not(num % 9))
        {
            return 9;
        }
        return num % 9;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for (size_t i = 0; i < 100; i++)
    {
        auto res = s.addDigits(i);
        std::cout << i << ":" << res << std::endl;
    }

    return 0;
}
