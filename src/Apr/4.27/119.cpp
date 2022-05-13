/**
 * @file 119.cpp
 * @brief 杨辉三角II
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-27
 */
#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result(rowIndex + 1);
        result[0] = 1;
        for (int i = 1; i <= rowIndex; ++i)
        {
            for (int j = i; j >= 1; --j)
            {
                result[j] = result[j - 1] + result[j];
            }
        }
        result[rowIndex] = 1;
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    auto res = ans.getRow(3);
    println_vector(res);
    std::cout << std::endl;
    return 0;
}
