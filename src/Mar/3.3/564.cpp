/**
 * @file 564.cpp
 * @brief 寻找最近的回文数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-03-03
 */
#include <string>
#include <iostream>

using namespace std;

/**
 * @brief 考虑10，最近的回文数不是11，而是9
 * 考虑20，最近的回文数是22，不是11
 * 再考虑100，最近的回文数可以使101，也可以是99
 */
class Solution
{
public:
    string nearestPalindromic(string n)
    {
        string less;
        if (n.size() == 1)
        {
            less += (char)(n[0] - 1);
            return less;
        }
        less = n;
        int len = n.size();
        int start = len % 2 ? len / 2 + 1 : len / 2;
        for (size_t i = start; i < len; i++)
        {
            less[i] = less[len - i - 1];
        }

        return less;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.nearestPalindromic("12921");
    std::cout << res << std::endl;
    return 0;
}
