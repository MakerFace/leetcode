/**
 * @file 1758.cpp
 * @brief 生成交替二进制字符串的最少操作数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        string s1(s.size(), '0'), s2(s.size(), '1');
        for (int i = 1; i < s.size(); i += 2)
        {
            s1[i] = '1';
            s2[i] = '0';
        }
        int c1 = 0, c2 = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s1[i] != s[i])
                ++c1;
            if (s2[i] != s[i])
                ++c2;
        }
        return min(c1, c2);
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    string str;
    while (cin >> str)
    {
        std::cout << ans.minOperations(str) << std::endl;
    }
    return 0;
}
