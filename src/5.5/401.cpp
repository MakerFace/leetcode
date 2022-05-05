/**
 * @file 401.cpp
 * @brief 二进制手表
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-05
 */
#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;
class Solution
{
    int hour = 3;
    int minute = 5;

public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        if (turnedOn > (hour + minute))
            return vector<string>();
        if (not turnedOn)
            return vector<string>(1, "0:00");
        vector<string> result;
        for (int i = 0; i < 12; ++i)
        {
            int h = countOne(i);
            for (int j = 0; j < 60; ++j)
            {
                int m = countOne(j);
                if ((h + m) == turnedOn)
                {
                    string temp = to_string(i) + ":";
                    if (j < 10)
                        temp += "0";
                    temp += to_string(j);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }

private:
    int countOne(int n)
    {
        int count = 0;
        while (n)
        {
            if (n % 2)
                ++count;
            n /= 2;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int n;
    while (cin >> n)
    {
        print_vector(ans.readBinaryWatch(n));
        std::cout << std::endl;
    }
    return 0;
}
