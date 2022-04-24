/**
 * @file whd.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-21
 */

#include <bits/stdc++.h>
#include "common/utils.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int n, p, x;
    cin >> n >> p >> x;
    vector<long long> nums(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
        sum += nums[i];
        for (int j = i; j > 0 && nums[j] > nums[j - 1]; --j)
        {
            swap(nums[j], nums[j - 1]);
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        int m = (x - ((sum - nums[i]) % x)) % x;
        if (m == 0)
        {
            m = (p - m) / x - (nums[i] <= p); // 减去0，再减去自己
        }
        else
        {
            m = (p - m) / x + 1;
        }
        res += m;
        while (i < n && nums[i] == nums[i + 1])
        {
            ++i;
            res += m;
        }
    }
    std::cout << res << std::endl;
    return 0;
}
