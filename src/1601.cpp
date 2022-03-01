/**
 * @file 1601.cpp
 * @brief 最多可达成的请求数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-02-24
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        queue<int> requeue;
        requeue.push(0);
        while (not requeue.empty() or not requests.empty())
        {
            
        }

        return 1;
    }
};

int main()
{
    Solution s;
    int n;
    int r, t;
    cin >> n;
    vector<vector<int>> req;
    for (size_t i = 0; i < n; i++)
    {
        cin >> r >> t;
        req.push_back({r, t});
    }
    auto res = s.maximumRequests(n, req);
    std::cout << res << std::endl;
}