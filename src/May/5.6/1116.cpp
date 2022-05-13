/**
 * @file 1116.cpp
 * @brief 打印零与奇偶数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
using namespace std;

class ZeroEvenOdd
{
private:
    int n;
    int x;
    mutex zero_lock, odd_lock, even_lock;

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
        x = 1;
        odd_lock.lock();
        even_lock.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        while (x <= n)
        {
            zero_lock.lock();
            if (x > n)
            {
                odd_lock.unlock();
                even_lock.unlock();
                break;
            }
            printNumber(0);
            if (x % 2)
                odd_lock.unlock();
            else
                even_lock.unlock();
        }
    }

    void even(function<void(int)> printNumber)
    {
        while (true)
        {
            even_lock.lock();
            if (x > n)
                break;
            printNumber(x);
            ++x;
            zero_lock.unlock();
            if (x > n)
                break;
        }
    }

    void odd(function<void(int)> printNumber)
    {
        while (true)
        {
            odd_lock.lock();
            if (x > n)
                break;
            printNumber(x);
            ++x;
            zero_lock.unlock();
            if (x > n)
                break;
        }
    }
};

int main(int argc, char const *argv[])
{
    ZeroEvenOdd ans(8);
    auto printNumber = [](int x)
    {
        std::cout << x;
    };
    thread t1([&]()
              { ans.zero(printNumber); }),
        t2([&]()
           { ans.even(printNumber); }),
        t3([&]()
           { ans.odd(printNumber); });
    t1.detach();
    t2.detach();
    t3.join();
    std::cout << std::endl;
    return 0;
}
