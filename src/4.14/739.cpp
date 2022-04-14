/**
 * @file 739.cpp
 * @brief 每日温度
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-14
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res;
        res.resize(temperatures.size());
        for (size_t i = 0; i < temperatures.size(); ++i)
        {
            res[i] = 0;
            for (size_t j = i + 1; j < temperatures.size(); ++j)
            {
                ++res[i];
                if (temperatures[j] > temperatures[i])
                {
                    break;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> temperatures = {30, 60, 90};
    auto res = s.dailyTemperatures(temperatures);
    for (auto var : res)
    {
        std::cout << var << " ";
    }
    std::cout << std::endl;
    return 0;
}
