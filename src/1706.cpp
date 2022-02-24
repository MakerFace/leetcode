/**
 * @file 1706.cpp
 * @brief 球会落何处
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-02-24
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    /**
     * @brief 判断是否可以通过一个方格
     * @param  grid             My Param doc
     * @return vector<int>
     */
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> answer;
        answer.resize(n);
        for (size_t i = 0; i < n; i++)
        {
            answer[i] = i;
            size_t col = i;
            for (size_t row = 0; row < m; row++)
            {
                if (not passGrid(grid, row, col))
                {
                    col = -1;
                    break;
                }
            }
            answer[i] = col;
        }
        return answer;
    }

private:
    inline bool passGrid(vector<vector<int>> &grid, size_t i, size_t &j)
    {
        if (grid[i][j] == 1)
        {
            if (j == grid[i].size() - 1 or    ///* 走到右边界
                grid[i][j + 1] != grid[i][j]) ///* 或与右边相反卡住
            {
                return false;
            }
            ++j;
            return true;
        }
        else
        {
            if (j == 0 or                     ///* 走到左边界
                grid[i][j - 1] != grid[i][j]) ///* 或与左边相反卡住
            {
                return false;
            }
            --j;
            return true;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> grid = {{-1, 1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, 1, -1, -1, -1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, 1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, 1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, -1, -1, -1, -1}};
    auto res = s.findBall(grid);
    for (auto i = res.begin(); i != res.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    return 0;
}
