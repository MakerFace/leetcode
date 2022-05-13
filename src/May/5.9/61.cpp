/**
 * @file 61.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-09
 */
#include <bits/stdc++.h>
#include "common/ListNode.hpp"
using namespace std;

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (not k or not head)
        {
            return head;
        }

        ListNode *p = head;
        int size = 0;
        while (p)
        {
            p = p->next;
            ++size;
        }
        p = head;
        k = size - (k % size);
        ListNode *q = head;
        while (k)
        {
            q = p;
            p = p->next;
            if (!p)
                p = head;
            --k;
        }
        ListNode *end = p;
        while (end->next)
        {
            end = end->next;
        }
        end->next = head;
        q->next = nullptr;
        head = p;
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int k;
    while (cin >> k)
    {
        auto head = vector2list({1, 5});
        auto res = ans.rotateRight(head, k);
        print_list(res);
    }
    return 0;
}
