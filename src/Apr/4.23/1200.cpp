/**
 * @file 1200.cpp
 * @brief 最小绝对差
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-23
 */

#include <bits/stdc++.h>
#include "common/utils.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        unordered_map<int, vector<vector<int>>> map;
        sort(arr.begin(), arr.end());
        int len = INT_MAX;
        for (size_t i = 1; i < arr.size(); ++i)
        {
            int temp = arr[i] - arr[i - 1];
            len = min(len, temp);
            auto iter = map.find(temp);
            if (iter == map.end())
            {
                map.insert(make_pair(temp, vector<vector<int>>({{arr[i - 1], arr[i]}})));
            }
            else
            {
                iter->second.emplace_back(vector<int>({arr[i - 1], arr[i]}));
            }
        }
        return map.find(len)->second;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr = {3, 8, -10, 23, 19, -4, -14, 27};
    auto res = s.minimumAbsDifference(arr);
    for (auto r : res)
    {
        println_vector(r);
    }
    return 0;
}
