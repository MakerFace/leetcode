/**
 * @file 36.cpp
 * @brief 有效的数独
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
#include "common/Matrix.hpp"
using namespace std;

class Solution
{
    unordered_map<string, set<char>> map;

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            map.insert(make_pair("row" + to_string(i), set<char>()));
            map.insert(make_pair("col" + to_string(i), set<char>()));
            map.insert(make_pair("grid" + to_string(i), set<char>()));
        }
        string row, col, grid;
        for (int i = 0; i < 9; ++i)
        {
            row = "row" + to_string(i);
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                auto iter = map.find(row);
                auto res = iter->second.insert(board[i][j]);
                if (not res.second)
                    return false;

                col = "col" + to_string(j);
                iter = map.find(col);
                res = iter->second.insert(board[i][j]);
                if (not res.second)
                    return false;

                int g = (i / 3) * 3 + j / 3;
                string grid = "grid" + to_string(g);
                iter = map.find(grid);
                res = iter->second.insert(board[i][j]);
                if (not res.second)
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Matrix<char> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution ans;
    std::cout << boolalpha << ans.isValidSudoku(board) << std::endl;
    return 0;
}
