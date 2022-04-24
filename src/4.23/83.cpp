/**
 * @file 83.cpp
 * @brief 删除排序链表中的重复元素
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-23
 */

#include <bits/stdc++.h>
#include "common/utils.hpp"
#include "common/ListNode.hpp"

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *first = head->next;
        ListNode *second = head;
        while (first != nullptr)
        {
            if (first->val != second->val)
            {
                first = first->next;
                second = second->next;
            }
            else
            {
                second->next = first->next;
                delete first;
                first = second->next;
            }
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto root = vector2list({1, 1, 2, 3, 3});
    auto res = s.deleteDuplicates(root);
    print_list(res);
    return 0;
}