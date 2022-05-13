/**
 * @file 78.cpp
 * @brief 子集
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-26
 */
#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        /**
         * @brief 迭代法
         */
        vector<vector<int>> result;
        int n = nums.size();
        vector<int> temp;
        for (int mask = 0; mask < (1 << n); ++mask)
        {
            temp.clear();
            for (int i = 0; i < n; ++i)
            {
                if (mask & (1 << i))
                {
                    temp.push_back(nums[i]);
                }
            }
            result.push_back(temp);
        }
        return result;
        /* 递归、回溯法
        int n = pow(2, nums.size());
        int top = 0;
        int next = 0;
        int len = nums.size();
        vector<vector<int>> result(n);
        stack<int> s;
        vector<int> temp(len);

        s.push(0);
        result[0] = vector<int>();
        for (int i = 1; i < n; ++i)
        {
            next = s.top();
            if (next >= len)
            {
                top -= 2;
                s.pop();
                next = s.top();
                s.pop();
            }
            temp[top++] = nums[next++];
            s.push(next);
            result[i] = vector<int>(temp.begin(), temp.begin() + top);
        }
        return result;
        */
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> nums = {1, 2, 3};
    auto res = ans.subsets(nums);
    std::cout << "[";
    for (auto var : res)
    {
        println_vector(var);
        std::cout << ",";
    }
    cout << "\b]" << endl;
    return 0;
}
