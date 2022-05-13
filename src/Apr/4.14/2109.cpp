/**
 * @file 2109.cpp
 * @brief 向字符串添加空格
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-14
 */
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        string res;
        res.resize(s.size() + spaces.size());
        int i = 0, j = 0;
        for (; i < s.size(); ++i)
        {
            if (j < spaces.size() && i == spaces[j])
            {
                res[i + j] = ' ';
                ++j;
            }

            res[i + j] = s[i];
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "LeetcodeHelpsMeLearn";
    vector<int> spaces = {8, 13, 15};
    auto res = s.addSpaces(str, spaces);
    std::cout << "*" << res << "*" << std::endl;
    std::cout << "Leetcode Helps Me Learn" << std::endl;
    std::cout << res.size() << std::endl;
    string result = "Leetcode Helps Me Learn";
    std::cout << result.size() << std::endl;
    std::cout << boolalpha << (res == result) << std::endl;
    return 0;
}
