/**
 * @file 48.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-07
 */
#include <bits/stdc++.h>
#include "common/Matrix.hpp"
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int len = matrix.size();
        for (int i = 0, j = 0; len >= 2; ++i, ++j, len -= 2)
            rotate(i, j, len, matrix);
    }

private:
    void rotate(int i, int j, int n, vector<vector<int>> &matrix)
    {
        int ni = i;
        int nj = n - 1 + i;
        int k = j;
        for (int l = 0; l < n - 1; ++l, ++k, ++ni)
        {
            swap(matrix[i][k], matrix[ni][nj]);
        }
        k = j;
        for (int l = 0; l < n - 1; ++l, ++k, --nj)
        {
            swap(matrix[i][k], matrix[ni][nj]);
        }
        k = j;
        for (int l = 0; l < n - 1; ++l, ++k, --ni)
        {
            swap(matrix[i][k], matrix[ni][nj]);
        }
    }
};

int main(int argc, char const *argv[])
{
    Matrix<int> matrix = {{5, 1, 5, 4, 9, 11, 2, 3, 4},
                          {2, 2, 3, 4, 8, 10, 2, 3, 4},
                          {13, 1, 3, 3, 6, 7, 2, 3, 4},
                          {15, 14, 12, 5, 6, 16, 2, 3, 4},
                          {1, 2, 3, 4, 5, 6, 2, 3, 4},
                          {7, 8, 9, 0, 1, 2, 2, 3, 4},
                          {1, 2, 3, 4, 5, 6, 7, 8, 9},
                          {1, 23, 4, 54, 6, 7, 8, 8, 9},
                          {1, 2, 3, 4, 5, 6, 7, 8, 98}};
    Solution ans;
    ans.rotate(matrix);
    print_matrix(matrix);
    return 0;
}
