/**
 * @file 1598.cpp
 * @brief 文件夹操作日志搜集器
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int steps = 0;
        for (auto var : logs)
        {
            if (var == "../")
            {
                if (steps > 0)
                    --steps;
            }
            else if (var == "./")
            {
                continue;
            }
            else
            {
                ++steps;
            }
        }
        return steps;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<string> logs = {"d1/", "../", "../", "../"};
    std::cout << ans.minOperations(logs) << std::endl;
    return 0;
}
