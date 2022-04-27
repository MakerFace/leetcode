/**
 * @file 82.cpp
 * @brief 删除排序链表中的重复元素II
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-26
 */
#include <bits/stdc++.h>
#include "common/ListNode.hpp"
using namespace std;

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *p = head->next;
        ListNode *q = head;
        while (head && head->next &&
               head->val == head->next->val)
        {
            p = head;
            while (p && p->val == head->val)
            {
                p = p->next;
            }
            head = p;
        }

        if (p && p == head)
        {
            q = p;
            p = p->next;
        }
        while (p)
        {
            while (p && p->next &&
                   p->val == p->next->val)
            {
                ListNode *t = p;
                while (t && t->val == p->val)
                {
                    t = t->next;
                }
                q->next = t;
                p = t;
                continue;
            }
            if (p)
            {
                q = q->next;
                p = p->next;
            }
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *root = vector2list({1, 2, 2, 3, 3, 4, 4, 5, 5});
    Solution ans;
    auto res = ans.deleteDuplicates(root);
    print_list(res);
    return 0;
}
