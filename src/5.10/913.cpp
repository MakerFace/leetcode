/**
 * @file 913.cpp
 * @brief 猫和老鼠
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-10
 */
#include <bits/stdc++.h>
#include "common/Matrix.hpp"
using namespace std;

class Solution
{
    typedef vector<vector<vector<int>>> MatrixIII;
    typedef vector<vector<int>> MatrixII;
    const int MOUSE_TURN = 0, CAT_TURN = 1;
    const int DRAW = 0, MOUSE_WIN = 1, CAT_WIN = 2;

public:
    /**
     * @brief 最优策略：玩家总选择
     * 1. 争取将必胜状态留给自己，必败状态留给对方
     * 2. 无法必胜，则将必和状态留给对方
     * 动态规划时间复杂度高O(n^5)
     * 因此使用Top排序
     */
    int catMouseGame(vector<vector<int>> &graph)
    {
        int n = graph.size();
        MatrixIII degrees(n, MatrixII(n, vector<int>(2)));
        MatrixIII results(n, MatrixII(n, vector<int>(2)));
        int cat = 2, mouse = 1;
        int turn = 1;
        queue<tuple<int, int, int>> qu;
        // 初始化度矩阵
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                degrees[i][j][MOUSE_TURN] = graph[i].size();
                degrees[i][j][CAT_TURN] = graph[j].size();
            }
        }
        // 猫不能走0，因此所有与0相邻的点出度减一
        for (auto g : graph[0])
        {
            for (int j = 1; j < n; ++j)
            {
                degrees[0][j][CAT_TURN]--;
            }
        }
        // 对所有猫状态，老鼠进入0则老鼠获胜，必胜条件
        for (int j = 1; j < n; ++j)
        {
            results[0][j][MOUSE_TURN] = MOUSE_WIN;
            results[0][j][CAT_TURN] = MOUSE_WIN;
            qu.emplace(0, j, MOUSE_TURN);
            qu.emplace(0, j, CAT_TURN);
        }
        // 对所有非0鼠状态，猫鼠在同一个节点则猫获胜，必胜条件
        for (int i = 1; i < n; ++i)
        {
            results[i][i][MOUSE_TURN] = CAT_WIN;
            results[i][i][CAT_TURN] = CAT_WIN;
            qu.emplace(i, i, MOUSE_TURN);
            qu.emplace(i, i, CAT_TURN);
        }
        while (not qu.empty())
        {
            auto t = qu.front();
            mouse = get<0>(t);
            cat = get<1>(t);
            turn = get<2>(t);
            qu.pop();
            int result = results[mouse][cat][turn];
            auto prev_state = get_prev_states(mouse, cat, turn);
        }
    }

private:
    vector<tuple<int, int, int>> get_prev_states(int mouse, int cat, int turn)
    {
    }
};

int main(int argc, char const *argv[])
{
    Matrix<int> graph = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
    Solution ans;
    std::cout << ans.catMouseGame(graph) << std::endl;
    return 0;
}
