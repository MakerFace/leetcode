/**
 * @file 145.cpp
 * @brief 二叉树的后序遍历
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-26
 */
#include <bits/stdc++.h>
#include "common/TreeNode.hpp"
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (p || !s.empty())
        {
            if (p)
            {
                while (p)
                {
                    s.push(p);
                    p = p->left;
                }
            }
            else
            {
                p = s.top();
                if (!p->right)
                {
                    result.push_back(p->val);
                    s.pop();
                }
                TreeNode *q = p;
                while (!s.empty() && s.top()->right == q)
                {
                    result.push_back(s.top()->val);
                    q = s.top();
                    s.pop();
                }
                p = p->right;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    TreeNode *root = list2tree({2, null, 3, null, 1});
    auto res = ans.postorderTraversal(root);
    println_vector(res);
    std::cout << std::endl;
    return 0;
}
