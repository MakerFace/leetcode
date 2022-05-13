/**
 * @file 933.cpp
 * @brief 最近的请求次数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
using namespace std;
class RecentCounter
{
    queue<int> q;

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        while (not q.empty() and
               (t - 3000) > q.front())
        {
            q.pop();
        }
        if (q.empty())
        {
            // q.push(t - 3000);
            q.push(t);
        }
        else
        {
            q.push(t);
        }
        return q.size();
    }
};

int main(int argc, char const *argv[])
{
    RecentCounter ans;
    std::cout << ans.ping(1) << std::endl;
    std::cout << ans.ping(100) << std::endl;
    std::cout << ans.ping(3001) << std::endl;
    std::cout << ans.ping(3002) << std::endl;
    return 0;
}
