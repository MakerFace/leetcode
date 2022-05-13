/**
 * @file 696.cpp
 * @brief 计数二进制子串
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-22
 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int res = 0;
        size_t i = 0;
        int count0 = 0;
        int count1 = 0;
        int flag = 0;
        while (i < s.size())
        {
            if (i > 0 && s[i] != s[i - 1])
            {
                ++flag;
                if (flag == 2)
                {
                    flag = 1;
                    res += min(count0, count1);
                    if (s[i] == '0')
                        count0 = 0;
                    else
                        count1 = 0;
                }
            }
            if (s[i] == '0')
                ++count0;
            else
                ++count1;
            ++i;
        }
        res += min(count0, count1);
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.countBinarySubstrings("10101") << std::endl;
    return 0;
}
