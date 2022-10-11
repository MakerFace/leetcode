/**
 * @file 429.cpp
 * @brief N叉树的层次遍历
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-21
 */

#include <bits/stdc++.h>
#include "common/Node.hpp"
#include "common/utils.hpp"

using tree::Node;
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res;
        queue<Node *> queue;
        queue.push(root);
        int curChild = 1;
        int nextChild;
        while (!queue.empty())
        {
            nextChild = 0;
            Node *temp = queue.front();
            vector<int> v;
            for (int i = 0; i < curChild; ++i)
            {
                nextChild += temp->children.size();
                for (auto var : temp->children)
                {
                    queue.push(var);
                }
                v.push_back(temp->val);
                queue.pop();
                temp = queue.front();
            }
            curChild = nextChild;
            res.emplace_back(v);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Node *root = list2Tree({1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null, 9, 10, null, null, 11, null, 12, null, 13, null, null, 14});
    Solution s;
    auto res = s.levelOrder(root);
    for (auto r : res)
    {
        println_vector(r);
    }
    return 0;
}
