/**
 * @file 385.cpp
 * @brief 迷你语法分析器
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-15
 */
#include <bits/stdc++.h>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
private:
    int value;
    vector<NestedInteger> values;
    bool isList;

public:
    // Constructor initializes an empty nested list.
    NestedInteger() : isList(false) { value = -1; }

    // Constructor initializes a single integer.
    NestedInteger(int value) : isList(false)
    {
        this->value = value;
    }

    NestedInteger(const NestedInteger &nestedInteger)
    {
        if (!nestedInteger.isList)
        {
            isList = false;
            value = nestedInteger.value;
        }
        else
        {
            isList = true;
            for (auto &&var : nestedInteger.values)
            {
                values.emplace_back(var);
            }
        }
    }

    NestedInteger(NestedInteger &&nestedInteger)
    {
        if (!nestedInteger.isList)
        {
            isList = false;
            value = nestedInteger.value;
        }
        else
        {
            isList = true;
            values.swap(nestedInteger.values);
        }
    }

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const { return !isList; }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const { return value; }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value)
    {
        this->value = value;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni)
    {
        isList = true;
        values.emplace_back(ni);
        // if (isList)
        // {
        //     values.emplace_back(ni);
        // }
        // else
        // {
        //     isList = true;
        //     values.emplace_back(NestedInteger(value));
        //     values.emplace_back(ni);
        // }
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const { return values; }

    friend ostream &operator<<(ostream &os, const NestedInteger &value)
    {
        if (!value.isList)
        {
            os << value.value;
            os << ",";
        }
        else
        {
            os << "[";
            for (auto &&var : value.values)
            {
                os << var << ",";
            }
            os << "\b],";
        }
        os << "\b";
        return os;
    }
};

/**
 * @brief 词法分析器
 * s=[0...9]|[|]| - |,:s
 * 其中，一个可解析的数字，要么是个单独的数字（只有一个数），要么就以[开始，以]结束的一组数
 * 一组数可以是一些,分隔的数，也可以是,[分隔的list。
 */
class Solution
{
public:
    NestedInteger deserialize(string s)
    {
        stack<NestedInteger> numbers;
        stack<char> squares;
        NestedInteger *top = nullptr;

        for (size_t i = 0; i < s.size(); ++i)
        {
            if (isInteger(s[i]))
            {
                auto number = deserializeInteger(s, i);
                if (!squares.empty() && isLeftSquare(squares.top()))
                {
                    numbers.top().add(number.getInteger());
                }
                else
                {
                    if (numbers.empty())
                    {
                        top = new NestedInteger(number);
                    }
                    else
                        numbers.top().add(number);
                }
            }
            if (isLeftSquare(s[i]))
            {
                squares.push(s[i]);
                numbers.push(NestedInteger());
            }
            else if (isRightSquare(s[i]))
            {
                top = nullptr;
                while (!squares.empty() && !isLeftSquare(squares.top())) // list
                {
                    squares.pop();
                    top = new NestedInteger(numbers.top());
                    numbers.pop();
                }
                if (numbers.empty())
                {
                    break;
                }
                if (top == nullptr) // [] list only one element
                {
                    top = new NestedInteger(numbers.top());
                    numbers.pop();
                }
                if (!numbers.empty())
                {
                    squares.pop(); // [ 左括号出栈
                    numbers.top().add(*top);
                    delete top;
                }
                else
                {
                    break;
                }
            }
            else if (isComma(s[i]))
            {
                if (!isComma(squares.top())) //操作符栈不是comma
                {
                    squares.push(s[i]);
                }
            }
            else if (!isInteger(s[i]))
            {
                std::cout << "Error" << std::endl;
            }
        }
        NestedInteger result(*top);
        delete top;
        top = nullptr;
        return result;
    }

private:
    /**
     * @brief 从当前字符串开始解析，直到遇到第一个非数字结束[,|]|EOF]
     */
    NestedInteger deserializeInteger(const string &s, size_t &i)
    {
        int num = 0;
        bool negative = false;
        if (s[i] == '-')
        {
            negative = true;
            ++i;
        }
        while (i < s.size() && isInteger(s[i]))
        {
            num *= 10;
            num += s[i] - '0';
            ++i;
        }
        if (negative)
        {
            num = -num;
        }
        --i;
        return NestedInteger(num);
    }

    inline bool isInteger(char s)
    {
        return (s >= '0' && s <= '9') || s == '-';
    }

    inline bool isComma(char s)
    {
        return s == ',';
    }

    inline bool isLeftSquare(char s)
    {
        return s == '[';
    }

    inline bool isRightSquare(char s)
    {
        return s == ']';
    }
};

int main(int argc, char const *argv[])
{
    // "[-324,[22,-33],3211]"
    // NestedInteger res;
    // res.add(NestedInteger(-324));
    // NestedInteger list;
    // list.add(NestedInteger(22));
    // list.add(NestedInteger(-33));
    // res.add(list);
    // res.add(NestedInteger(3211));
    Solution s;
    auto res = s.deserialize("[]");
    cout << res << " \n";
    return 0;
}
