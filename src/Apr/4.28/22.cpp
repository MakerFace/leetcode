/**
 * @file 22.cpp
 * @brief 括号生成
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-28
 */
#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        result.push_back("()");
        for (int i = 1; i < n; ++i)
        {
            int old_size = result.size();
            for (int j = 0; j < old_size; ++j)
            {
                if (result[j] + "()" != result[result.size() - 1])
                    result.push_back(result[j] + "()");
                // TODO 去重
                if ("()" + result[j] != result[result.size() - 1])
                    result.push_back("()" + result[j]);
            }
            for (int j = 0; j < old_size; ++j)
            {
                result[j] = "(" + result[j] + ")";
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int n;
    while (cin >> n)
    {
        auto res = ans.generateParenthesis(n);
        println_vector(res);
    }
    return 0;
}
