#pragma once
#include <bits/stdc++.h>
#define null -1

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *list2tree(std::initializer_list<int> l)
{
    TreeNode *root = nullptr;
    std::queue<TreeNode *> q;
    int count = 0;
    for (auto &i : l)
    {
        if (!root)
        {
            root = new TreeNode(i);
            q.push(root);
        }
        else
        {
            TreeNode *p = nullptr;
            if (i != -1)
                p = new TreeNode(i);
            if (count == 0)
            {
                q.front()->left = p;
            }
            else if (count == 1)
            {
                q.front()->right = p;
                q.pop();
            }
            if (p != nullptr)
            {
                q.push(p);
            }
            ++count;
            count %= 2;
        }
    }
    return root;
}

void print_tree(TreeNode *root)
{
    TreeNode *null_node = new TreeNode(-1);
    std::queue<TreeNode *> queue;
    std::vector<int> v;
    queue.push(root);
    int curChild = 1;
    int nextChild;
    while (!queue.empty())
    {
        nextChild = 0;
        for (int i = 0; i < curChild; ++i)
        {
            TreeNode *temp = queue.front();
            if (temp->val == -1)
            {
                // std::cout << "null,";
                v.push_back(-1);
            }
            else
            {
                // std::cout << temp->val << ",";
                v.push_back(temp->val);
                if (temp->left != nullptr)
                {
                    queue.push(temp->left);
                }
                else
                {
                    queue.push(null_node);
                }
                ++nextChild;
                if (temp->right != nullptr)
                {
                    queue.push(temp->right);
                }
                else
                {
                    queue.push(null_node);
                }
                ++nextChild;
            }
            queue.pop();
        }
        curChild = nextChild;
    }
    for (auto i = v.end() - 1; i != v.begin() && *i == -1; --i)
    {
        v.erase(i);
    }
    delete null_node;
    std::cout << "[" << v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] == -1)
            std::cout << ",null";
        else
            std::cout << "," << v[i];
    }
    std::cout << "]" << std::endl;
}