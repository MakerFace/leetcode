/**
 * @file 1115.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
using namespace std;

class FooBar
{
private:
    int n;
    mutex foo_lock, bar_lock;

public:
    FooBar(int n)
    {
        this->n = n;
        bar_lock.lock();
    }

    void foo(function<void()> printFoo)
    {

        for (int i = 0; i < n; i++)
        {
            foo_lock.lock();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            bar_lock.unlock();
        }
    }

    void bar(function<void()> printBar)
    {

        for (int i = 0; i < n; i++)
        {
            bar_lock.lock();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            foo_lock.unlock();
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
