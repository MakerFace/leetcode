/**
 * @file 1184.cpp
 * @brief 公交站间距离
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-24
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int n = distance.size();
        int i = start;
        int result1 = 0;
        int result2 = 0;
        while (i != destination)
        {
            result1 += distance[i];
            ++i;
            i %= n;
        }
        i = destination;
        while (i != start)
        {
            result2 += distance[i];
            ++i;
            i %= n;
        }
        return min(result1, result2);
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> distance = {1, 2, 3, 4};
    int start = 0;
    int destination = 2;
    cout << ans.distanceBetweenBusStops(distance, start, destination) << endl;
    return 0;
}
