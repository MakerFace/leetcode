/**
 * @file 1114.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
using namespace std;

class Foo
{
    mutex lock_first;
    mutex lock_second;

public:
    Foo()
    {
        lock_first.lock();
        lock_second.lock();
    }

    void first(function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        lock_first.unlock();
    }

    void second(function<void()> printSecond)
    {
        lock_first.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        lock_first.unlock();
        lock_second.unlock();
    }

    void third(function<void()> printThird)
    {
        lock_second.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        lock_second.unlock();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
