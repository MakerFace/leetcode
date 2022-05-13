/**
 * @file 404.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-05
 */
#include <bits/stdc++.h>
#include "common/TreeNode.hpp"
using namespace std;

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (not root)
            return 0;
        int left = 0;
        if (root->left and not root->left->left and not root->left->right)
            left += root->left->val;
        left += sumOfLeftLeaves(root->left);
        left += sumOfLeftLeaves(root->right);
        return left;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    auto root = list2tree({1, 2, 3, 4, 5});
    std::cout << ans.sumOfLeftLeaves(root) << std::endl;
    return 0;
}
