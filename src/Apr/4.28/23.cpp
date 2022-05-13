/**
 * @file 23.cpp
 * @brief 合并K个升序链表
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-28
 */

#include <bits/stdc++.h>
#include "common/ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        bool work = true;
        ListNode *root = nullptr;
        ListNode *end = nullptr;
        int temp = -1;
        while (work)
        {
            work = false;
            for (size_t i = 0; i < lists.size(); ++i)
            {
                if (lists[i])
                {
                    if (temp == -1)
                    {
                        temp = i;
                        work = true;
                    }
                    if (lists[temp])
                    {
                        if (lists[temp]->val > lists[i]->val)
                        {
                            temp = i;
                            work = true;
                        }
                    }
                }
            }
            if (!work)
                break;
            if (!root)
            {
                root = lists[temp];
                end = root;
                lists[temp] = lists[temp]->next;
            }
            else
            {
                end->next = lists[temp];
                lists[temp] = lists[temp]->next;
                end = end->next;
            }
            temp = -1;
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<ListNode *> lists;
    lists.push_back(vector2list({1, 4, 5}));
    lists.push_back(vector2list({1, 3, 4}));
    lists.push_back(vector2list({2, 6}));
    auto res = ans.mergeKLists(lists);
    print_list(res);
    return 0;
}
