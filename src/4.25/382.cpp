/**
 * @file 382.cpp
 * @brief 链表随机节点
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
private:
    ListNode *head;
    ListNode *p;
    int n = -1;

public:
    Solution(ListNode *head) : head(head)
    {
        p = nullptr;
    }

    int getRandom()
    {
        static default_random_engine e;
        if (n == -1)
        {
            while (p)
            {
                ++n;
                p = p->next;
            }
        }
        int next = e() % n;
        while (next)
        {
            if (p == nullptr)
                p = head;
            p = p->next;
            --next;
        }
        return p->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
