/**
 * @file 38.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string result = "1";
        for (int i = 1; i < n; ++i)
        {
            string temp;
            for (int j = 0; j < result.size(); ++j)
            {
                int count = j;
                while (j + 1 < result.size() and result[j] == result[j + 1])
                {
                    ++j;
                }
                temp += to_string(j - count + 1) + result[j];
            }
            result = temp;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int n;
    while (cin >> n)
        std::cout << ans.countAndSay(n) << std::endl;
    return 0;
}
