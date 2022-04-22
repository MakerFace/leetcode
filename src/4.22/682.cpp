/**
 * @file 682.cpp
 * @brief 棒球比赛
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-22
 */
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        int res = 0, x;
        vector<int> nums;
        nums.reserve(ops.size());
        for (size_t i = 0; i < ops.size(); ++i)
        {
            if (ops[i] == "C")
            {
                res -= nums[nums.size() - 1];
                nums.erase(nums.end() - 1);
            }
            else if (ops[i] == "D")
            {
                x = nums[nums.size() - 1] * 2;
                res += x;
                nums.push_back(x);
            }
            else if (ops[i] == "+")
            {
                x = nums[nums.size() - 1] + nums[nums.size() - 2];
                res += x;
                nums.push_back(x);
            }
            else
            {
                x = atoi(ops[i].c_str());
                res += x;
                nums.push_back(x);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> ops = {"1"};
    std::cout << s.calPoints(ops) << std::endl;
    return 0;
}
