/**
 * @file 58.cpp
 * @brief 最后一个单词长度
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-02-24
 */
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        bool start = false;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == ' ' and not count)
            {
                continue;
            }
            else if (s[i] == ' ' and count)
            {
                break;
            }
            ++count;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.lengthOfLastWord("Hello World");
    std::cout << res << std::endl;
    return 0;
}
