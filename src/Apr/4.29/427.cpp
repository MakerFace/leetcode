/**
 * @file 427.cpp
 * @brief 建立四叉树
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-29
 */

#include <bits/stdc++.h>

#include "common/Matrix.hpp"
#include "common/QuadTree.hpp"
using namespace std;

class Solution {
 public:
  Node *construct(vector<vector<int>> &grid) {
    int length = grid.size();
    if (length == 1) {
      return new Node(grid[0][0], true);
    }
    Node *root = constructChild(grid, 0, 0, length);
    return root;
  }

 private:
  /**
   * @brief
   * @param  grid
   * @param  tfx topLeft_x
   * @param  tfy topLeft_y
   * @param  length
   * @return Node*
   */
  Node *constructChild(const vector<vector<int>> &grid, int tfx, int tfy,
                       int length) {
    Node *node;
    bool isLeaf = true;
    if (length == 2) {
      int val = grid[tfx][tfy];
      isLeaf = grid[tfx][tfy] == val and grid[tfx][tfy + 1] == val and
               grid[tfx + 1][tfy] == val and grid[tfx + 1][tfy + 1] == val;
      node = new Node(val, isLeaf);
      if (!isLeaf) {
        node->topLeft = new Node(grid[tfx][tfy], true);
        node->topRight = new Node(grid[tfx][tfy + 1], true);
        node->bottomLeft = new Node(grid[tfx + 1][tfy], true);
        node->bottomRight = new Node(grid[tfx + 1][tfy + 1], true);
      }
      return node;
    } else {
      length = length / 2;
      Node *topLeft = constructChild(grid, tfx, tfy, length);
      Node *topRight = constructChild(grid, tfx, tfy + length, length);
      Node *bottomLeft = constructChild(grid, tfx + length, tfy, length);
      Node *bottomRight =
          constructChild(grid, tfx + length, tfy + length, length);
      int val = topLeft->val;
      isLeaf = (topLeft->isLeaf and topRight->isLeaf and bottomLeft->isLeaf and
                bottomRight->isLeaf) and
               (topLeft->val == val and topRight->val == val and
                bottomLeft->val == val and bottomRight->val == val);
      node = new Node(val, isLeaf);
      if (!isLeaf) {
        node->topLeft = topLeft;
        node->topRight = topRight;
        node->bottomLeft = bottomLeft;
        node->bottomRight = bottomRight;
      }
      return node;
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  Matrix<int> grid = {{1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
                      {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
                      {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}};
  auto root = ans.construct(grid);
  print_quad_tree(root);
  return 0;
}
