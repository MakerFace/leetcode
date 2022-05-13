/**
 * @file 1331.cpp
 * @brief 数组序号转换
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-29
 */
#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        unordered_map<int, vector<int>> map;
        vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); ++i)
        {
            auto iter = map.find(arr[i]);
            if (iter == map.end())
            {
                map.insert(make_pair(arr[i], vector<int>({i})));
            }
            else
            {
                iter->second.push_back(i);
            }
        }
        sort(arr.begin(), arr.end());
        int count = 1;
        for (int i = 0; i < arr.size(); ++i, ++count)
        {
            auto iter = map.find(arr[i]);
            for (auto idx : iter->second)
            {
                result[idx] = count;
            }
            while (i + 1 < arr.size() && arr[i] == arr[i + 1])
            {
                ++i;
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> arr = {100, 100, 100};
    auto res = ans.arrayRankTransform(arr);
    println_vector(res);
    std::cout << std::endl;
    return 0;
}
