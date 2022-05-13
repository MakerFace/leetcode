/**
 * @file 98.cpp
 * @brief 验证二叉搜索树
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-25
 */

#include <bits/stdc++.h>
#include "common/TreeNode.hpp"
using namespace std;

class Solution
{
public:
    /**
     * @brief 中序遍历顺序
     * @param  root             My Param doc
     * @return true
     * @return false
     */
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> s;
        TreeNode *p = root;
        int pre;
        bool found = false; // 最左节点, 最小值
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
                if (!found)
                {
                    found = true;
                    pre = p->val;
                }
                else if (pre >= p->val)
                {
                    return false;
                }
                else
                {
                    pre = p->val;
                }
                s.pop();
                p = p->right;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    TreeNode *root = list2tree({2, 2, 2});
    std::cout << boolalpha << ans.isValidBST(root) << std::endl;
    return 0;
}
