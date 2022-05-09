/**
 * @file 33.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-09
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        int mid;
        while (i < j and nums[i] > nums[j])
        {
            mid = (i + j) / 2;
            if (nums[mid] < nums[i])
            {
                j = mid;
            }
            else
            {
                i = mid + 1;
            }
        }
        j = nums.size() - 1;
        if (target <= nums[j]) // [i,j]
        {
            return half_search(nums, i, j, target);
        }
        else // [0, i-1]
        {
            return half_search(nums, 0, i - 1, target);
        }
    }

private:
    int half_search(vector<int> nums, int start, int end, int target)
    {
        int mid;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            else if (target > nums[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int target;
    vector<int> nums = {1,2,3};
    while (cin >> target)
    {
        std::cout << ans.search(nums, target) << std::endl;
    }
    return 0;
}
