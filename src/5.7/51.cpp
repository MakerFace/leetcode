/**
 * @file 51.cpp
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
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        for (int i = 0; i < n - 1; ++i)
        {
            vector<string> temp(n, string(n, '.'));
            temp[0][i] = 'Q';
            if (create_board(n, temp))
            {
                result.emplace_back(temp);
            }
        }
    }

private:
    bool create_board(int n, vector<string> &board)
    {
        for (int i = 1; i < n; ++i)
        {
            
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
