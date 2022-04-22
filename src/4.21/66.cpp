/**
 * @file 66.cpp
 * @brief 加一
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-21
 */

#include <bits/stdc++.h>
#include "common/utils.hpp"

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> res(digits.size());
        int cur = digits.size() - 1;
        auto digit = digits.crbegin();
        int value = *digit + 1;
        res[cur--] = value % 10;
        value /= 10;
        for (++digit; digit != digits.crend(); ++digit)
        {
            value += *digit;
            res[cur--] = value % 10;
            value /= 10;
        }
        if (value != 0)
        {
            res.insert(res.begin(), 1, value % 10);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> digits = {9, 9, 9, 9};
    print_vector(s.plusOne(digits));
    return 0;
}
