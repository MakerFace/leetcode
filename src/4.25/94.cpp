/**
 * @file 94.cpp
 * @brief 二叉树的中序遍历
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-25
 */
#include <bits/stdc++.h>
#include "common/TreeNode.hpp"
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
        {
            return vector<int>();
        }
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (p || !s.empty())
        {
            if (p)
            {
                s.push(p);
                while (p->left)
                {
                    s.push(p->left);
                    p = p->left;
                }
                p = nullptr;
            }
            else // 右子树
            {
                p = s.top();
                result.push_back(p->val);
                s.pop();
                p = p->right;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution ans;
    auto root = list2tree({1});
    auto res = ans.inorderTraversal(root);
    print_vector(res);
    return 0;
}
