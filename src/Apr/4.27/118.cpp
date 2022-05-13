/**
 * @file 118.cpp
 * @brief 杨辉三角
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-27
 */

#include <bits/stdc++.h>
#include "common/Matrix.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        result.reserve(numRows);
        result.emplace_back(vector<int>({1}));
        for (int i = 1; i < numRows; ++i)
        {
            vector<int> temp(result[i - 1].size() + 1);
            int j;
            temp[0] = 1;
            for (j = 1; j < temp.size() - 1; ++j)
            {
                temp[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            temp[j] = 1;
            result.emplace_back(temp);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.generate(5);
    print_matrix(res);
    std::cout << std::endl;
    return 0;
}
