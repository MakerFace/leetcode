/**
 * @file 108.cpp
 * @brief 将有序数组转换为二叉搜索树
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-27
 */
#include <bits/stdc++.h>
#include "common/TreeNode.hpp"
using namespace std;

class Solution
{
    typedef struct Index
    {
        int s, m, e;
        Index(int s, int m, int e) : s(s), m(m), e(e) {}
    } Index;

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int s = 0, e = nums.size() - 1;
        int m = (s + e) / 2;
        TreeNode *root = new TreeNode(nums[m]);
        queue<Index> indexes;
        queue<TreeNode *> nodes;
        nodes.push(root);
        indexes.push(Index(s, m, e));
        int h = ceil(log2(e + 1));
        for (int i = 0; i < h; ++i)
        {
            int curChild = nodes.size();
            for (int j = 0; j < curChild; ++j)
            {
                TreeNode *p = nodes.front();
                auto index = indexes.front();
                nodes.pop();
                indexes.pop();
                s = index.s;
                e = index.m - 1;
                if (s <= e)
                {
                    m = (s + e) / 2;
                    p->left = new TreeNode(nums[m]);
                    indexes.push(Index(s, m, e));
                    nodes.push(p->left);
                }
                s = index.m + 1;
                e = index.e;
                if (s <= e)
                {
                    m = (s + e) / 2;
                    p->right = new TreeNode(nums[m]);
                    indexes.push(Index(s, m, e));
                    nodes.push(p->right);
                }
            }
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    // vector<int> nums = {1, 9};
    // vector<int> nums = {-10,-3,0,5,9};
    auto res = ans.sortedArrayToBST(nums);
    println_tree(res);
    std::cout << std::endl;
    return 0;
}
