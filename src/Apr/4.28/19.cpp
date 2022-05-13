/**
 * @file 19.cpp
 * @brief 删除链表的倒数第N个节点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p = head, *q = head;
        for (int i = 0; i < n; i++)
        {
            p = p->next;
            if (!p)
                p = head;
        }
        if (p == q)
            return head->next;
        while (p && p->next)
        {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return head;
    }
};
int main(int argc, char const *argv[])
{
    Solution ans;
    int n;
    while (cin >> n)
    {
        auto root = vector2list({1});
        auto res = ans.removeNthFromEnd(root, n);
        print_list(res);
    }
    return 0;
}
