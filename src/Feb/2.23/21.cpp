/**
 * @file 21.cpp
 * @brief 合并有序链表
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-02-23
 */
#include <iostream>
#include <vector>
#include <common/ListNode.hpp>
using namespace std;
/**
 * Definition for singly-linked list.
 */

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = nullptr;
        ListNode *ptr;
        int val;
        while (list1 != nullptr and list2 != nullptr)
        {
            if (list1->val > list2->val)
            {
                val = list2->val;
                list2 = list2->next;
            }
            else
            {
                val = list1->val;
                list1 = list1->next;
            }
            if (head == nullptr)
            {
                head = new ListNode(val);
                ptr = head;
            }
            else
            {
                ptr->next = new ListNode(val);
                ptr = ptr->next;
            }
        }
        while (list1 != nullptr)
        {
            if (head == nullptr)
            {
                head = new ListNode(list1->val);
                ptr = head;
            }
            else
            {
                ptr->next = new ListNode(list1->val);
                ptr = ptr->next;
            }
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            if (head == nullptr)
            {
                head = new ListNode(list2->val);
                ptr = head;
            }
            else
            {
                ptr->next = new ListNode(list2->val);
                ptr = ptr->next;
            }
            list2 = list2->next;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *l1, *l2;
    std::cout << "vector to list" << std::endl;
    l1 = vector2list({});
    l2 = vector2list({0});
    auto res = s.mergeTwoLists(l1, l2);
    while (res != nullptr)
    {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}
