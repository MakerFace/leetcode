/**
 * @file offer.45.cpp
 * @brief 把数组排列成最小的数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-14
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    string minNumber(vector<int> &nums)
    {
        string res;
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i; j < nums.size(); j++)
            {
                if (compare(nums[j], nums[i]))
                {
                    swap(nums[i], nums[j]);
                }
            }
            res.append(to_string(nums[i]));
        }
        return res;
    }

private:
    /**
     * @brief 位不足的用最高位补足，再比较
     */
    bool compare(int a, int b)
    {
        if (a == 0)
        {
            return true;
        }
        if (b == 0)
        {
            return false;
        }

        int _a = a, _b = b;
        int count1 = 0, count2 = 0;
        int first1, first2;
        count1 = counter(a, first1);
        count2 = counter(b, first2);
        while (count1 < count2)
        {
            a *= 10;
            a += first1;
            ++count1;
        }
        while (count1 > count2)
        {
            b *= 10;
            b += first2;
            ++count2;
        }
        if (a == b) // 比较大数的前两位
        {
            if (_a > _b)
            {
                first1 = _a / pow(10, count2 - 1);
                first2 = _a / pow(10, count1 - 2) - first1 * 10;
                return first1 < first2;
            }
            if (_a < _b)
            {
                first1 = _b / pow(10, count2 - 1);
                first2 = _b / pow(10, count1 - 2) - first1 * 10;
                return first1 > first2;
            }

            return first1 < first2;
        }
        return a < b;
    }

    int counter(int n, int &first)
    {
        int res = 0;
        while (n != 0)
        {
            ++res;
            first = n;
            n /= 10;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {803, 8038, 121, 12};
    // vector<int> nums = {10, 2};
    auto res = s.minNumber(nums);
    std::cout << res << std::endl;
    return 0;
}
