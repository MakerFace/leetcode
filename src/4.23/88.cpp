/**
 * @file 88.cpp
 * @brief 合并两个有序数组
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-23
 */

#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (m == 0)
        {
            nums1.swap(nums2);
            swap(m, n);
        }
        int cur = m + n - 1;
        int i = m - 1;
        for (int j = n - 1; j >= 0; --j)
        {
            while (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[cur--] = nums1[i];
                --i;
            }
            nums1[cur--] = nums2[j];
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {4, 5, 6, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3};
    int m = 3, n = 3;
    Solution ans;
    ans.merge(nums1, m, nums2, n);
    println_vector(nums1);
    return 0;
}
