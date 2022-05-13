/**
 * @file 8.cpp
 * @brief 字符串转换整数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-28
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int result = 0;
        bool negative = false;
        bool stop = false;
        int i = 0;
        while (s[i] == ' ')
            ++i;
        if (s[i] == '-')
        {
            ++i;
            negative = true;
        }
        else if (s[i] == '+')
        {
            ++i;
        }
        while (!stop)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (result == 214748364)
                {
                    if (negative)
                    {
                        if (s[i] >= '8')
                        {
                            return INT_MIN;
                        }
                    }
                    else
                    {
                        if (s[i] >= '7')
                        {
                            return INT_MAX;
                        }
                    }
                }
                else if (result > 214748364)
                {
                    if (negative)
                        return INT_MIN;
                    else
                        return INT_MAX;
                }

                result *= 10;
                result += s[i] - '0';
            }
            else
            {
                break;
            }
            ++i;
        }
        if (negative)
            result = -result;
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    string str;
    while (cin >> str)
        std::cout << ans.myAtoi(str) << std::endl;
    return 0;
}
