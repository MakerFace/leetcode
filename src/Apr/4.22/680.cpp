/**
 * @file 680.cpp
 * @brief 验证回文字符串
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-22
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        bool res = true;
        bool work = false;
        int start = 0, end = s.size() - 1;
        int del_1, del_2;
        while (start < end)
        {
            if (!work && s[start] != s[end]) // 第一次不等
            {
                work = true;
                del_1 = start;
                del_2 = end;
                ++start; //删除前面的
                continue;
            }
            else if (work && s[start] != s[end])
            {
                if (res) // 第二次不等
                {
                    res = false;
                    start = del_1;
                    end = del_2 - 1; //删除后面的
                    continue;
                }
                else // 第三次不等
                {
                    return false;
                }
            }
            ++start;
            --end;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << boolalpha << s.validPalindrome("abacbabba") << std::endl;
    return 0;
}
