/**
 * @file 93.cpp
 * @brief 复原IP地址
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-26
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        for (int l = 1; l < 4 && s.size(); ++l)
        {
            for (int m = l + 1; m < l + 4 && m < s.size(); ++m)
            {
                for (int r = m + 1; r < m + 4 && r < s.size(); ++r)
                {
                    string temp[4];
                    temp[0] = s.substr(0, l);
                    temp[1] = s.substr(l, m - l);
                    temp[2] = s.substr(m, r - m);
                    temp[3] = s.substr(r, s.size() - r);
                    int i = 0;
                    string str;
                    for (; i < 4; ++i)
                        if (isValidAddress(temp[i]))
                            str += temp[i] + ".";
                        else
                            break;
                    if (i == 4)
                    {
                        result.emplace_back(str.substr(0, str.size() - 1));
                    }
                }
            }
        }
        return result;
    }

private:
    bool isValidAddress(string &s)
    {
        if (s.size() > 3 || s.size() == 0)
            return false;
        if (s[0] == '0' && s.size() > 1)
            return false;
        if (s[0] >= '3' && s.size() == 3)
            return false;
        if (s[0] == '2' && s[1] == '5' && s.size() == 3 && s[2] >= '6') // 256~259
            return false;
        if (s[0] == '2' && s[1] >= '6' && s.size() == 3) // 260~299
            return false;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    string s;
    while (cin >> s)
    {
        auto res = ans.restoreIpAddresses(s);
        if (!res.empty())
            std::cout << res[0];
        for (int i = 1; i < res.size(); ++i)
        {
            std::cout << "," << res[i];
        }
        std::cout << std::endl;
    }
    return 0;
}
