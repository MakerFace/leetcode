/**
 * @file 12.cpp
 * @brief 整树转罗马数字
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-28
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string result;
        int first = num / 1000;
        if (first)
        {
            for (int i = 0; i < first; ++i)
            {
                result += "M";
            }
            num %= 1000;
        }
        first = num / 100;
        if (first)
        {
            if (first == 4)
            {
                result += "CD";
            }
            else if (first == 9)
            {
                result += "CM";
            }
            else
            {
                if (first > 4)
                {
                    result += "D";
                    first -= 5;
                }
                for (int i = 0; i < first; ++i)
                {
                    result += "C";
                }
            }
            num %= 100;
        }
        first = num / 10;
        if (first)
        {

            if (first == 4)
            {
                result += "XL";
            }
            else if (first == 9)
            {
                result += "XC";
            }
            else
            {
                if (first > 4)
                {
                    result += "L";
                    first -= 5;
                }
                for (int i = 0; i < first; ++i)
                {
                    result += "X";
                }
            }
            num %= 10;
        }
        first = num;
        if (first)
        {
            if (first == 4)
            {
                result += "IV";
            }
            else if (first == 9)
            {
                result += "IX";
            }
            else
            {
                if (first > 4)
                {
                    result += "V";
                    first -= 5;
                }
                for (int i = 0; i < first; ++i)
                {
                    result += "I";
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int num;
    while (cin >> num)
        std::cout << ans.intToRoman(num) << std::endl;
    return 0;
}
