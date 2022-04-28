/**
 * @file 111.cpp
 * @brief 二叉树的最小深度
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-27
 */
#include <bits/stdc++.h>
#include "common/TreeNode.hpp"
using namespace std;

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int result = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            result++;
            int cur = q.size();
            for (int i = 0; i < cur; ++i)
            {
                TreeNode *p = q.front();
                q.pop();
                if (p && p->left)
                {
                    q.push(p->left);
                }
                if (p && p->right)
                {
                    q.push(p->right);
                }
                if (!p->left && !p->right)
                {
                    return result;
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    auto root = list2tree({2, null, 3, null, 4, null, 5, null, 6});
    std::cout << ans.minDepth(root) << std::endl;
    return 0;
}
