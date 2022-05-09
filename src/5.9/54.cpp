/**
 * @file 54.cpp
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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int e_r = matrix.size(), e_c = matrix[0].size();
        vector<int> result(e_r * e_c);
        int s_r = 0, s_c = 0;
        int r = 0, c = 0;
        int cur = 0;
        while (s_r < e_r and s_c < e_c)
        {
            for (c = s_c, r = s_r; c < e_c; ++c)
            {
                result[cur++] = matrix[r][c];
            }
            for (c = e_c - 1, ++r; r < e_r; ++r)
            {
                result[cur++] = matrix[r][c];
            }
            for (r = e_r - 1, --c; s_r + 1 < e_r and c >= s_c; --c)
            {
                result[cur++] = matrix[r][c];
            }
            for (c = s_c, --r; s_c + 1 < e_c and r > s_r; --r)
            {
                result[cur++] = matrix[r][c];
            }
            ++s_c;
            ++s_r;
            --e_c;
            --e_r;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    Matrix<int> matrix = {{7}, {9}, {6}};
    auto res = ans.spiralOrder(matrix);
    print_vector(res);
    return 0;
}
