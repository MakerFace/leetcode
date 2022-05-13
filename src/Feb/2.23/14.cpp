/**
 * @file 14.cpp
 * @brief 最长公共前缀
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-02-23
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res;
        char temp = ' ';
        bool stop = false;
        for (size_t j = 0; not stop; ++j) //列优先
        {
            for (size_t i = 0; i < strs.size(); ++i)
            {
                if (i == 0 and j < strs[i].size())
                {
                    temp = strs[i][j];
                }
                else if (j > strs[i].size())
                {
                    stop = true;
                    break;
                }

                if (j >= strs[i].size() or strs[i][j] != temp)
                {
                    stop = true;
                    break;
                }
            }
            if (not stop)
            {
                res += temp;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> strs = {"dog", "racecar", "car"};
    auto res = s.longestCommonPrefix(strs);
    std::cout << res << std::endl;
    return 0;
}
