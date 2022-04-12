/**
 * @file 35.cpp
 * @brief 搜索插入位置
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-02-24
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.empty())
        {
            return 0;
        }
        int i = 0;
        int j = nums.size() - 1;

        int mid;
        // 二分法有误，j=mid+1
        while (i < j - 1)
        {
            mid = (i + j) / 2;
            if (nums[mid] < target)
            {
                i = mid;
            }
            else if (nums[mid] > target)
            {
                j = mid;
            }
            else
            {
                return mid;
            }
        }
        if (nums[i] >= target)
        {
            return i;
        }
        else if (nums[j] < target)
        {
            return j + 1;
        }
        else if (nums[j] >= target)
        {
            return j;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 3, 4, 6};
    int target = 2;
    Solution s;
    auto res = s.searchInsert(nums, target);
    std::cout << res << std::endl;
    return 0;
}
