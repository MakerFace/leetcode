/**
 * @file 86.cpp
 * @brief 分割链表
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *p, *q;
        p = head;
        while (head && head->val >= x) // 找到第一个小于x的节点
        {
            q = head;
            head = head->next;
        }
        if (!head) // 没有小于x的节点
            return p;
        if (p && p != head)
        {
            q->next = head->next;
            head->next = p;
        }
        p = head;
        while (p && p->val < x) // 找到第一次出现大于等于x的节点的父节点
        {
            q = p;
            p = p->next;
        }
        p = q;
        while (p)
        {
            ListNode *t = nullptr;
            while (p && p->val >= x)
            {
                t = p;
                p = p->next;
            }
            if (t && p)
            {
                t->next = p->next;
                p->next = q->next;
                q->next = p;
                q = p;
                p = t;
                continue;
            }
            if (p)
                p = p->next;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *root = vector2list({1});
    Solution ans;
    auto res = ans.partition(root, 0);
    print_list(res);
    return 0;
}
