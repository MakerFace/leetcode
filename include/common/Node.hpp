#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <queue>
#include <initializer_list>
#define null -1

class Node
{
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

Node *list2Tree(std::initializer_list<int> l)
{
    std::queue<Node *> queue;
    Node *head = nullptr;
    for (auto iter = l.begin(); iter != l.end();)
    {
        if (queue.empty())
        {
            head = new Node(*iter);
            queue.push(head);
            ++iter;
        }
        else
        {
            std::vector<Node *> children;
            while ((iter != l.end()) && (*iter != -1))
            {
                Node *temp = new Node(*iter);
                children.emplace_back(temp);
                queue.push(temp);
                ++iter;
            }
            queue.front()->children.swap(children);
            queue.pop();
        }
        if (iter != l.end())
        {
            ++iter;
        }
    }
    return head;
}

#endif // NODE_HPP
