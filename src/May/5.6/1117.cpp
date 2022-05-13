/**
 * @file 1117.cpp
 * @brief H2O 生成
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
using namespace std;

class H2O
{
    mutex o_lock;
    mutex h_lock;
    mutex m;
    int count;

public:
    H2O()
    {
        count = 0;
    }

    void hydrogen(function<void()> releaseHydrogen)
    {
        m.lock();
        if (count == 0 or count == 2)
        {
            h_lock.lock();
        }
        ++count;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if (count >= 2)
            o_lock.unlock();
        m.unlock();
    }

    void oxygen(function<void()> releaseOxygen)
    {
        o_lock.lock();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        count = 0;
        h_lock.unlock();
    }
};

int main(int argc, char const *argv[])
{
    string str;
    H2O h2o;
    thread th, to;
    while (cin >> str)
    {
    }
    return 0;
}
