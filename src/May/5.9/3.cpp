/**
 * @file 3.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-09
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @brief 暴力解法，时间超限
     * @brief 哈希集合解法，双指针指向边界，右边界始终向右移动，新增字符如果存在于集合中，则左边界向右移动，直到插入成功为止
     */
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> set;
        size_t result = 0;
        size_t i = 0, j = 0;
        while (j < s.size())
        {
            auto res = set.insert(s[j]);
            while (not res.second)
            {
                auto iter = set.find(s[i]);
                set.erase(iter);
                ++i;
                res = set.insert(s[j]);
            }
            result = max(result, set.size());
            ++j;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    string s;
    while (cin >> s)
        std::cout << ans.lengthOfLongestSubstring(s) << std::endl;
    return 0;
}
