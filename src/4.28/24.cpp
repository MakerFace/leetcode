/**
 * @file 24.cpp
 * @brief 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *p = head, *q = head->next;
        while (p && q)
        {
            swap(p->val, q->val);
            p = q->next;
            if (p)
                q = p->next;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    auto root = vector2list({1, 2, 3, 4});
    auto res = ans.swapPairs(root);
    print_list(res);
    return 0;
}
