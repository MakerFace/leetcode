/**
 * @file 101.cpp
 * @brief 对称二叉树
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
    bool isSymmetric(TreeNode *root)
    {
        return symmetric(root->left, root->right);
    }

private:
    bool symmetric(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        if (left && right && left->val == right->val)
        {
            return symmetric(left->left, right->right) && symmetric(left->right, right->left);
        }
        else
            return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    TreeNode *root = list2tree({1, 2, 2, null, 3, null, 3});
    std::cout << boolalpha << ans.isSymmetric(root) << std::endl;
    return 0;
}
