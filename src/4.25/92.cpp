/**
 * @file 92.cpp
 * @brief 反转链表II
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-25
 */

#include <bits/stdc++.h>
#include "common/ListNode.hpp"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        ListNode *p = head;
        int cur = 1;
        while (cur + 1 < left)
        {
            p = p->next;
            ++cur;
        }
        ListNode *q = p->next;
        while (cur + 1 < right)
        {
            if (q->next != nullptr)
            {
                ListNode *second = p->next;
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = second;
            }
            ++cur;
        }
        if (left == 1)
        {
            head = p->next;
            p->next = q->next;
            q->next = p;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    auto root = vector2list({1, 2, 3, 4, 5});
    Solution ans;
    int left, right;
    cin >> left >> right;
    auto p = ans.reverseBetween(root, left, right);
    print_list(p);
    return 0;
}
