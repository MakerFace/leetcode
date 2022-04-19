/**
 * @file 821.cpp
 * @brief 字符的最短距离
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-19
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        vector<int> res;
        int pre = 0, next = 0;
        pre = find(s, c, 0);
        next = find(s, c, pre);
        res.resize(s.size());
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (i > next)
            {
                pre = next;
                next = find(s, c, i);
            }
            res[i] = min(i - pre, next - i);
        }
        return res;
    }

private:
    int find(string &s, char c, int pre)
    {
        for (int i = pre; i < s.size(); ++i){
            if (s[i] == c)
                return i;
        }
        return INT_MAX;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.shortestToChar("aaab", 'b');
    for (auto var : res)
    {
        std::cout << var << " ";
    }
    std::cout << std::endl;
    return 0;
}
