/**
 * @file 13.cpp
 * @brief 罗马数字转整数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-20
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case 'I':
                if (i + 1 < s.size() && s[i + 1] == 'V')
                {
                    ++i;
                    res += 4;
                }
                else if (i + 1 < s.size() && s[i + 1] == 'X')
                {
                    ++i;
                    res += 9;
                }
                else
                {
                    res += 1;
                }
                break;
            case 'V':
                res += 5;
                break;
            case 'X':
                if (i + 1 < s.size() && s[i + 1] == 'L')
                {
                    ++i;
                    res += 40;
                }
                else if (i + 1 < s.size() && s[i + 1] == 'C')
                {
                    ++i;
                    res += 90;
                }
                else
                {
                    res += 10;
                }
                break;
            case 'L':
                res += 50;
                break;
            case 'C':
                if (i + 1 < s.size() && s[i + 1] == 'D')
                {
                    ++i;
                    res += 400;
                }
                else if (i + 1 < s.size() && s[i + 1] == 'M')
                {
                    ++i;
                    res += 900;
                }
                else
                {
                    res += 100;
                }
                break;
            case 'D':
                res += 500;
                break;
            case 'M':
                res += 1000;
                break;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.romanToInt("MCMXCIV") << std::endl;
    return 0;
}
