/**
 * @file 90.cpp
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
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = pow(2, nums.size());
        int top = 0;
        int len = nums.size();
        vector<vector<int>> result;
        set<vector<int>> temp;
        vector<int> s(len);
        stack<int> stack;

        stack.push(0);
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; ++i)
        {
            int index = stack.top();
            if (index >= len)
            {
                top -= 2; // 出栈
                stack.pop();
                index = stack.top();
                stack.pop();
            }
            // 入栈
            s[top++] = nums[index++];
            stack.push(index);
            vector<int> t(s.begin(), s.begin() + top);
            temp.emplace(t);
        }

        result.reserve(n);
        result.emplace_back(vector<int>()); // 空集
        for (auto var : temp)
        {
            result.emplace_back(var);
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    auto res = ans.subsetsWithDup(nums);
    std::cout << "[";
    for (auto r : res)
    {
        print_vector(r);
        std::cout << ",";
    }
    std::cout << "\b]" << std::endl;
    return 0;
}
