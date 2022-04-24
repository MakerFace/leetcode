/**
 * @file 367.cpp
 * @brief 有效的完全平方数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-23
 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int result = 0;
        while (result < 46340 && result * result < num)
        {
            ++result;
        }
        return result * result == num;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    cin >> n;
    std::cout << boolalpha << s.isPerfectSquare(n) << std::endl;
    return 0;
}
