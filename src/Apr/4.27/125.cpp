/**
 * @file 125.cpp
 * @brief 验证回文串
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-27
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            while (i < j && !inSet(s[i]))
            {
                ++i;
            }
            while (i < j && !inSet(s[j]))
            {
                --j;
            }
            if (!judge(s[i], s[j]))
                return false;
            ++i;
            --j;
        }
        return true;
    }

private:
    bool inSet(char c)
    {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
    }

    bool judge(char a, char b)
    {
        if (a == b) // 同为大小写或数字
            return true;
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) // 不同时为大小写
            return a == b || a == b - 'A' + 'a' || a == b - 'a' + 'A';
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    char s[1024];
    while (cin.getline(s, 1024))
    {
        string str(s);
        std::cout << boolalpha << ans.isPalindrome(str) << std::endl;
    }
    return 0;
}
