/**
 * @file 6223.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-30
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <functional>
#include <limits>
#include <map>
#include <queue>
#include <utility>
#include <vector>

#include "common/TreeNode.hpp"
#include "common/Vector.hpp"

using namespace std;

class Solution {
 public:
  // 作者：endlesscheng
  // 链接：https://leetcode.cn/problems/height-of-binary-tree-after-subtree-removal-queries/solution/liang-bian-dfspythonjavacgo-by-endlessch-vvs4/
  vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
    unordered_map<TreeNode *, int> height;  // 每棵子树的高度
    function<int(TreeNode *)> get_height = [&](TreeNode *node) -> int {
      return node ? height[node] =
                        1 + max(get_height(node->left), get_height(node->right))
                  : 0;
    };
    get_height(root);

    int res[height.size() + 1];  // 每个节点的答案
    function<void(TreeNode *, int, int)> dfs = [&](TreeNode *node, int depth,
                                                   int rest_h) {
      if (node == nullptr) return;
      ++depth;
      res[node->val] = rest_h;
      dfs(node->left, depth, max(rest_h, depth + height[node->right]));
      dfs(node->right, depth, max(rest_h, depth + height[node->left]));
    };
    dfs(root, -1, 0);

    for (auto &q : queries) q = res[q];
    return queries;
  }

  // vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
  //   map<int, pair<int, int>> himap;  // top two height
  //   map<int, pair<int, int>> ndmap;  // node to height
  //   vector<int> ans;
  //   ans.reserve(queries.size());
  //   queue<TreeNode*> que;
  //   function<int(TreeNode*, int)> dfs;
  //   dfs = [&](TreeNode* root, int depth) -> int {  // depth当前树高
  //     if (not root) return 0;
  //     auto ldepth = dfs(root->left, depth + 1);   // 左子树高度
  //     auto rdepth = dfs(root->right, depth + 1);  // 右子树高度
  //     priority_queue<int, vector<int>, less<int>> pq;
  //     pq.emplace(ldepth);
  //     pq.emplace(rdepth);
  //     pq.emplace(himap[depth + 1].first);
  //     pq.emplace(himap[depth + 1].second);
  //     himap[depth + 1].first = pq.top();
  //     pq.pop();
  //     himap[depth + 1].second = pq.top();
  //     ndmap[root->val] = make_pair(depth, max(ldepth, rdepth) + 1);
  //     return max(ldepth, rdepth) + 1;  // 子树高度
  //   };
  //   dfs(root, 0);
  //   for (auto n : queries) {
  //     auto curdepth = ndmap[n].first;
  //     auto childdepth = ndmap[n].second;
  //     if (childdepth == himap[curdepth].first) {  // 剪掉最高的，就是第二高
  //       ans.emplace_back(curdepth + himap[curdepth].second - 1);
  //     } else {  // 剪掉其它的，不影响
  //       ans.emplace_back(curdepth + himap[curdepth].first - 1);
  //     }
  //   }
  //   return ans;
  // }
};

int main(int argc, char const *argv[]) {
  string s = string(PROJECT_PATH).append("/src/Oct/10.30/6223.txt");
  char buf[MAX_LINE_SIZE];
  ifstream in(s, ios::binary | ios::in);
  while (in.getline(buf, MAX_LINE_SIZE)) {
    Solution sol;
    auto root = string2tree(buf);
    in.getline(buf, MAX_LINE_SIZE);
    auto queries = string2vector(buf);
    auto ans = sol.treeQueries(root, queries);
    std::cout << ans << std::endl;
    delete_tree(root);
  }
  return 0;
}
