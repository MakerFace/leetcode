/**
 * @file 59.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-09
 */
#include <bits/stdc++.h>
#include "common/Matrix.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n));
        int row = 0, col = 0;
        int count = 1;
        while (row < n and col < n)
        {
            int i = row, j = col;
            for (; j < n; ++j)
            {
                result[i][j] = count++;
            }
            for (++i, --j; i < n; ++i)
            {
                result[i][j] = count++;
            }
            for (--i, --j; j >= col; --j)
            {
                result[i][j] = count++;
            }
            for (--i, ++j; i > row; --i)
            {
                result[i][j] = count++;
            }
            ++row;
            ++col;
            --n;
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
        auto res = ans.generateMatrix(n);
        print_matrix(res);
        std::cout << std::endl;
    }
    return 0;
}
