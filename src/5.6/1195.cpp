/**
 * @file 1195.cpp
 * @brief 交替打印字符串
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
#include <semaphore.h>
using namespace std;

class FizzBuzz
{
private:
    int n;
    int x;
    sem_t sem_fizz, sem_buzz, sem_fizzbuzz;

public:
    FizzBuzz(int n)
    {
        this->n = n;
        x = 1;
        sem_init(&sem_fizz, 0, 0);
        sem_init(&sem_buzz, 0, 0);
        sem_init(&sem_fizzbuzz, 0, 0);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        while (x < n)
        {
            sem_wait(&sem_fizz);
            if (x > n)
                break;
            printFizz();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        while (x < n)
        {
            sem_wait(&sem_buzz);
            if (x > n)
                break;
            printBuzz();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        while (x < n)
        {
            sem_wait(&sem_fizzbuzz);
            if (x > n)
                break;
            printFizzBuzz();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        while (x <= n)
        {
            if (not(x % 3) and not(x % 5))
            {
                sem_post(&sem_fizzbuzz);
            }
            else if (not(x % 3))
            {
                sem_post(&sem_fizz);
            }
            else if (not(x % 5))
            {
                sem_post(&sem_buzz);
            }
            else
            {
                printNumber(x);
            }
            ++x;
        }
        sem_post(&sem_fizz);
        sem_post(&sem_buzz);
        sem_post(&sem_fizzbuzz);
    }
};

int main(int argc, char const *argv[])
{
    FizzBuzz ans(15);
    return 0;
}
