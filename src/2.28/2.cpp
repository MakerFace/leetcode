/**
 * @file 2.cpp
 * @brief 两数相加
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-02-28
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr;
        ListNode *ptr = head;
        int sum = 0;
        while (l1 != nullptr and l2 != nullptr)
        {
            sum += l1->val + l2->val;
            if (head == nullptr)
            {
                head = new ListNode(sum % 10);
                ptr = head;
            }
            else
            {
                ptr->next = new ListNode(sum % 10);
                ptr = ptr->next;
            }

            sum /= 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        l1 = l1 != nullptr ? l1 : l2;
        while (l1 != nullptr)
        {
            sum += l1->val;
            if (head == nullptr)
            {
                head = new ListNode(sum % 10);
                ptr = head;
            }
            else
            {
                ptr->next = new ListNode(sum % 10);
                ptr = ptr->next;
            }
            sum /= 10;
            l1 = l1->next;
        }
        while (sum)
        {
            if (head == nullptr)
            {
                head = new ListNode(sum % 10);
                ptr = head;
            }
            else
            {
                ptr->next = new ListNode(sum % 10);
                ptr = ptr->next;
            }
            sum /= 10;
        }
        return head;
    }
};

ListNode *vector2list(const vector<int> v)
{
    ListNode *head = nullptr;
    ListNode *ptr;
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (head == nullptr)
        {
            head = new ListNode(v[i]);
            ptr = head;
        }
        else
        {
            ptr->next = new ListNode(v[i]);
            ptr = ptr->next;
        }
    }
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode *l1, *l2;
    l1 = vector2list({9,9,9,9,9,9,9});
    l2 = vector2list({9,9,9,9});
    if (l1 == nullptr or l2 == nullptr)
    {
        std::cout << "error" << std::endl;
        return 1;
    }

    Solution s;
    auto res = s.addTwoNumbers(l1, l2);
    while (res != nullptr)
    {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}
