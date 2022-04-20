#pragma once
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *vector2list(std::initializer_list<int> v)
{
    ListNode *head = nullptr;
    ListNode *ptr;
    for (auto var : v)
    {
        if (head == nullptr)
        {
            head = new ListNode(var);
            ptr = head;
        }
        else
        {
            ptr->next = new ListNode(var);
            ptr = ptr->next;
        }
    }
    return head;
}