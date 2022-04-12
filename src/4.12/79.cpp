/**
 * @file 79.cpp
 * @brief 单词搜索
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-12
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief DFS,BFS
 * //TODO 剪枝搜索
 */
class Solution
{
    typedef struct node
    {
        int i, j;
        bool used;
        int dir;

    public:
        node() : i(0), j(0), used(false) {}
        node(int i, int j, bool used) : i(i), j(j), used(used) {}
    };

public:
    bool exist(const vector<vector<char>> &board, string word)
    {
        stack<node> track;
        int i = 0, j = 0;
        int idx = 0;
        if (find(board, word[idx], i, j))
        {
            track.emplace(i, j, true);
        }
        
    }

private:
    bool find(const vector<vector<char>> &board, char c, int &i, int &j)
    {
        for (; i < board.size(); i++)
        {
            for (; j < board[i].size(); j++)
            {
                if (board[i][j] == c){
                    return true;
                }
            }
        }
        return false;
    }

    bool find_next(const vector<vector<char>> &board, char c, int &i, int &j, int dir){
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    auto res = s.exist(board, "ABCCED");
    std::cout << boolalpha << res << std::endl;
    return 0;
}
