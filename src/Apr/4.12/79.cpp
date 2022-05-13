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
class Solution {
  typedef struct node {
    char value;
    bool used;
    int dir;

   public:
    node() {}
    node(char v, bool used) : value(v), used(used), dir(0) {}
    void reset() {
      used = false;
      dir = 0;
    }
  } node;

  typedef struct back {
    int i, j;

   public:
    back(int i, int j) : i(i), j(j) {}
  } back;

 public:
  bool exist(const vector<vector<char>> &board, string word) {
    vector<vector<node>> graph;
    stack<back> track;
    size_t row = 0, col = 0;
    size_t idx = 0;
    graph.resize(board.size());
    // init graph
    for (size_t i = 0; i < board.size(); ++i) {
      graph[i].resize(board[i].size());
      for (size_t j = 0; j < board[i].size(); j++) {
        graph[i][j] = node(board[i][j], false);
        if (idx == 0 && board[i][j] == word[0])  // TODO 起始位置可能有多个
        {
          ++idx;
          row = i;
          col = j;
          track.emplace(row, col);
          graph[row][col].used = true;
        }
      }
    }
    if (idx == 0) {
      return false;
    }

    while (idx < word.size()) {
      if (find_next(graph, word[idx], row, col)) {
        track.emplace(row, col);
        graph[row][col].used = true;
        ++idx;
      } else if (!track.empty()) {
        graph[row][col].reset();
        // 回退
        track.pop();
        --idx;
        if (track.empty()) {
          if (find_head(graph, word[idx], row, col)) {
            track.emplace(row, col);
            graph[row][col].used = true;
            ++idx;
          } else {
            return false;
          }
        } else {
          row = track.top().i;
          col = track.top().j;
        }
      }
    }
    return true;
  }

 private:
  // TODO 控制回退
  bool find_next(vector<vector<node>> &graph, char c, size_t &row,
                 size_t &col) {
    size_t i = row, j = col;
    switch (graph[row][col].dir) {
      case 0:
        ++graph[row][col].dir;
        // up
        if (row > 0) {
          i = row - 1;
        }
        if (!graph[i][j].used && graph[i][j].value == c) {
          row = i;
          col = j;
          return true;
        }
      case 1:
        ++graph[row][col].dir;
        // right
        i = row;
        if (col < graph[0].size() - 1) {
          j = col + 1;
        }
        if (!graph[i][j].used && graph[i][j].value == c) {
          row = i;
          col = j;
          return true;
        }
      case 2:
        ++graph[row][col].dir;
        // down
        j = col;
        if (row < graph.size() - 1) {
          i = row + 1;
        }
        if (!graph[i][j].used && graph[i][j].value == c) {
          row = i;
          col = j;
          return true;
        }
      case 3:
        ++graph[row][col].dir;
        // left
        i = row;
        if (col > 0) {
          j = col - 1;
        }
        if (!graph[i][j].used && graph[i][j].value == c) {
          row = i;
          col = j;
          return true;
        }
      default:
        break;
    }
    return false;
  }

  bool find_head(vector<vector<node>> graph, char c, size_t &row, size_t &col) {
    ++col;
    for (; row < graph.size(); row++) {
      for (; col < graph[row].size(); col++) {
        if (graph[row][col].value == c) {
          return true;
        }
      }
      col = 0;
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<char>> board = {{'Z', 'Z', 'Z', 'Z', 'Z'},
                                {'Z', 'C', 'B', 'A', 'B'},
                                {'A', 'D', 'E', 'D', 'C'},
                                {'B', 'E', 'Z', 'Z', 'Z'}};
  auto res = s.exist(board, "ABEDCBA");
  std::cout << boolalpha << res << std::endl;
  return 0;
}
