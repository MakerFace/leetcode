/**
 * @file 345.cpp
 * @brief 反转字符串中的元音字母
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-19
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        size_t i = 0, j = s.size() - 1;
        while (i < j)
        {
            while (i < j && !vowel(s[i]))
            {
                ++i;
            }
            while (i < j && !vowel(s[j]))
            {
                --j;
            }
            if (i < j){
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }

private:
    bool vowel(char s)
    {
        return (s == 'a') || (s == 'e') || (s == 'i') || (s == 'o') || (s == 'u')
        ||(s == 'A') || (s == 'E') || (s == 'I') || (s == 'O') || (s == 'U');
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.reverseVowels("leetcode") << std::endl;
    return 0;
}
