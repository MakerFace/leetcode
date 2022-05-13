/**
 * @file 806.cpp
 * @brief 写字符串需要的行数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-12
 */
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        int lines = 1, col = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            col += widths[s[i] - 'a'];
            if (col >= 100)
            {
                ++lines;
                if (col != 100)
                {
                    col = widths[s[i] - 'a'];
                }
                else
                {
                    col = 0;
                }
            }
        }
        if (col == 0)
        {
            --lines;
            col = 100;
        }
        return {lines, col};
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> widths;
    char str[1000];
    cin.getline(str, 100, '\n');
    widths.resize(26);
    int i = 0;
    int idx = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ',')
        {
            ++idx;
        }
        else
        {
            widths[idx] *= 10;
            widths[idx] += str[i] - '0';
        }
        ++i;
    }
    cin.getline(str, 1000);
    string ss(str);
    auto res = s.numberOfLines(widths, ss);
    std::cout << res[0] << "," << res[1] << std::endl;
    return 0;
}
