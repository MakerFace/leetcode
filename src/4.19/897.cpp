/**
 * @file 897.cpp
 * @brief 递增顺序搜索树
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-19
 */
#include <bits/stdc++.h>
#include <common/TreeNode.h>
using namespace std;

class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *res = root;
        TreeNode *new_root = nullptr;
        TreeNode *_res;

        new_root = changeLeft(res);
        while (res->right != nullptr)
        {
            if (res->right->left != nullptr)
            {
                res->right = changeLeft(res->right);
            }
            res = res->right;
        }
        return new_root;
    }

private:
    TreeNode *changeLeft(TreeNode *root)
    {

        while (root->left != nullptr)
        {
            TreeNode *ptr = root->left;
            TreeNode *_res = root->left;
            while (ptr->right != nullptr)
            {
                ptr = ptr->right;
            }
            ptr->right = root;
            root->left = nullptr;
            root = _res;
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
