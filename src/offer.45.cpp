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
        int min = 9;
        unordered_map<int, vector<int>> map;
        for (size_t i = 0; i < nums.size(); i++)
        {
            vector<int> temp;
            int num = nums[i];
            if (num == 0)
            {
                temp.push_back(0);
                res.append("0");
                continue;
            }
            else
            {
                while (num != 0)
                {
                    if (min > num)
                        min = num;
                    temp.insert(temp.begin(), num % 10);
                    num /= 10;
                }
            }
            map.insert(pair<int, vector<int>>(i, temp));
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {10, 2};
    auto res = s.minNumber(nums);
    std::cout << res << std::endl;
    return 0;
}
