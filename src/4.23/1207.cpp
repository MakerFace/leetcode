/**
 * @file 1207.cpp
 * @brief 独一无二的出现次数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-23
 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        vector<int> count(arr.size());
        for (size_t i = 0; i < arr.size(); ++i)
        {
            ++count[arr[i] + 1000];
        }
        sort(count.begin(), count.end());
        for (size_t i = 1; i < count.size(); ++i)
        {
            if (count[i] != 0 && count[i] == count[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr = {1, 2, 2, 3, 3, 3};
    std::cout << boolalpha << s.uniqueOccurrences(arr) << std::endl;
    return 0;
}
