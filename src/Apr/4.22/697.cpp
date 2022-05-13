/**
 * @file 697.cpp
 * @brief 数组的度
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-22
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct Number
    {
        int val;
        int length;
        int start;
        int end;
        Number(int v, int i) : val(v), length(1), start(i), end(i) {}
    };

public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, Number> map;
        int size = 1;
        int length = INT_MAX;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            auto iter = map.find(nums[i]);
            if (iter == map.end())
            {
                map.insert(make_pair(nums[i], Number(nums[i], i)));
            }
            else
            {
                iter->second.end = i;
                iter->second.length++;
                size = max(size, iter->second.length);
            }
        }
        for (auto m : map)
        {
            if (m.second.length == size)
            {
                length = min(length, m.second.end - m.second.start + 1);
            }
        }
        return length;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1, 2};
    std::cout << s.findShortestSubArray(nums) << std::endl;
    return 0;
}
