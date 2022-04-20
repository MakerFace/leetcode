/**
 * @file 20.cpp
 * @brief 有效的括号
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-20
 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        for (auto v : s)
        {
            if (v == ')' || v == ']' || v == '}')
            {
                if (!match(stack, v))
                    return false;
            }
            else
                stack.push(v);
        }
        return stack.empty();
    }

private:
    bool match(stack<char> &s, char v)
    {
        char t;
        if (v == ')')
            t = '(';
        else if (v == ']')
            t = '[';
        else if (v == '}')
            t = '{';
        if (!s.empty() && s.top() == t)
        {
            s.pop();
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << boolalpha << s.isValid("()[]{}") << std::endl;
    return 0;
}