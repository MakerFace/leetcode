/**
 * @file 398.cpp
 * @brief 随机数索引
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-25
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> nums;
    default_random_engine e;
    unordered_map<int, vector<int>> map;

public:
    Solution(vector<int> &nums) : nums(nums)
    {
    }

    int pick(int target)
    {
        int start = 0, end = nums.size() - 1;
        auto iter = map.find(target);
        if (iter == map.end())
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                iter = map.find(nums[i]);
                if (iter == map.end())
                {
                    map.insert(make_pair(nums[i], vector<int>({i})));
                }
                else
                {
                    iter->second.push_back(i);
                }
            }
        }

        iter = map.find(target);
        return iter->second[e() % (iter->second.size())];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 3, 3};
    Solution ans(nums);
    std::cout << ans.pick(3) << std::endl;
    std::cout << ans.pick(3) << std::endl;
    std::cout << ans.pick(3) << std::endl;
    std::cout << ans.pick(3) << std::endl;
    std::cout << ans.pick(3) << std::endl;
    std::cout << ans.pick(3) << std::endl;
    std::cout << ans.pick(3) << std::endl;
    std::cout << ans.pick(3) << std::endl;
    std::cout << ans.pick(3) << std::endl;
    std::cout << ans.pick(3) << std::endl;
    std::cout << ans.pick(3) << std::endl;
    std::cout << ans.pick(3) << std::endl;
    std::cout << ans.pick(3) << std::endl;
    std::cout << ans.pick(3) << std::endl;
    return 0;
}
