/**
 * @file 25.cpp
 * @brief K个一组翻转链表
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-29
 */
#include <bits/stdc++.h>
#include "common/ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *p = head;
        ListNode *q = head;
        ListNode *temp;
        int i;
        for (i = 0; i < k && q; ++i)
        {
            q = q->next;
        }
        if (not q and i < k)
        {
            return head;
        }
        else
        {
            while (p->next != q)
            {
                temp = p->next->next;
                p->next->next = head;
                head = p->next;
                p->next = temp;
            }
        }
        while (p)
        {
            for (i = 0; i < k && q; ++i)
            {
                q = q->next;
            }
            if (not q and i < k)
            {
                return head;
            }
            ListNode *end = p->next;
            while (end->next != q)
            {
                temp = end->next->next;
                end->next->next = p->next;
                p->next = end->next;
                end->next = temp;
            }
            p = end;
        }
        return head;
    }
};
int main(int argc, char const *argv[])
{
    Solution ans;
    int n;
    auto root = vector2list({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20});
    while (cin >> n)
    {
        auto res = ans.reverseKGroup(root, n);
        print_list(res);
    }
    return 0;
}
