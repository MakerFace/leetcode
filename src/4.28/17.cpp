/**
 * @file 17.cpp
 * @brief  电话号码的字母组合
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
    vector<string> letterCombinations(string digits)
    {
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        if (digits == "")
        {
            return result;
        }
        int index = digits[0] - '0';
        for (int k = 0; k < map[index].size(); ++k)
        {
            result.push_back(string(1, map[index][k]));
        }
        for (int i = 1; i < digits.size(); ++i)
        {
            index = digits[i] - '0';
            int old_size = result.size();
            for (int j = 1; j < map[index].size(); ++j)
            {
                for (int k = 0; k < old_size; ++k)
                {
                    result.push_back(result[k] + map[index][j]);
                }
            }
            for (int k = 0; k < old_size; ++k)
            {
                result[k] += map[index][0];
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    string digits;
    while (cin >> digits)
    {
        auto res = ans.letterCombinations(digits);
        println_vector(res);
        std::cout << std::endl;
    }
    return 0;
}
