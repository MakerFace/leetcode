/**
 * @file 104.cpp
 * @brief 二叉树的最大深度
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
    /**
     * @brief 层次遍历
     */
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int result = 0;
        queue<TreeNode *> q;
        int curChild = 1;
        int nextChild;
        q.push(root);
        while (!q.empty())
        {
            result++;
            nextChild = 0;
            for (int i = 0; i < curChild; ++i)
            {
                TreeNode *p = q.front();
                q.pop();
                if (p->left)
                {
                    q.push(p->left);
                    nextChild++;
                }
                if (p->right)
                {
                    q.push(p->right);
                    nextChild++;
                }
            }
            curChild = nextChild;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    auto root = list2tree({3, 9, 20, null, null, 15, 7, 1});
    std::cout << ans.maxDepth(root) << std::endl;
    return 0;
}
