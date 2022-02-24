/**
 * @file 917.cpp
 * @brief 反转字母
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-02-23
 */

#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int start = 0;
        int end = s.length() - 1;
        while (start < end)
        {
            while (not isAlphabet(s[start]))
            {
                ++start;
            }
            while (not isAlphabet(s[end]))
            {
                --end;
            }
            if (start >= end)
            {
                break;
            }
            std::swap(s[start], s[end]);
            ++start;
            --end;
        }
        return s;
    }

private:
    inline bool isAlphabet(char c)
    {
        return (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z');
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "7_28]";
    str = s.reverseOnlyLetters(str);
    std::cout << str << std::endl;
    return 0;
}
