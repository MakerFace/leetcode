/**
 * @file 1287.cpp
 * @brief 有序数组中出现次数超过25%的元素
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-29
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int len = arr.size() * 0.25;
        unordered_map<int, int> map;
        for (auto a : arr)
        {
            auto iter = map.find(a);
            if (iter == map.end())
            {
                map.insert(make_pair(a, 1));
            }
            else
            {
                iter->second++;
                if (iter->second > len)
                {
                    return iter->first;
                }
            }
        }
        return arr[0];
    }
};
int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    std::cout << ans.findSpecialInteger(arr) << std::endl;
    return 0;
}
