/**
 * @file 110.cpp
 * @brief 平衡二叉树
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
     * @brief 后序遍历
     */
    bool isBalanced(TreeNode *root)
    {
        stack<TreeNode *> s;
        stack<int> length;
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
                TreeNode *q = p;
                if (p->right == nullptr)
                {
                    s.pop();
                    if (p->left)
                    {
                        if (length.top() >= 2)
                            return false;
                        length.top()++;
                    }
                }
                if (p->left == p->right && p->left == nullptr)
                {
                    length.push(1);
                }
                while (!s.empty() && s.top()->right == q)
                {
                    int left = 0;
                    int right = 0;
                    q = s.top();
                    s.pop();
                    if (q->right != nullptr)
                    {
                        right = length.top();
                        length.pop();
                    }
                    if (q->left != nullptr)
                    {
                        left = length.top();
                        length.pop();
                    }
                    if (abs(left - right) >= 2)
                    {
                        return false;
                    }
                    length.push(max(left, right) + 1);
                }
                p = p->right;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    auto root = list2tree({3, 1, null, null, 2});
    std::cout << boolalpha << ans.isBalanced(root) << std::endl;
    return 0;
}
