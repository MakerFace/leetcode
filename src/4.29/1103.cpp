/**
 * @file 1103.cpp
 * @brief 分糖果II
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-29
 */
#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;
class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> result(num_people);
        int cur = 0;
        int n = 1;
        while (candies > 0)
        {
            result[cur++] += n;
            cur %= num_people;
            candies -= n++;
            if (candies < n)
            {
                n = candies;
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution ans;
    int candies, num_people;
    while (cin >> candies >> num_people)
    {
        auto res = ans.distributeCandies(candies, num_people);
        print_vector(res);
        std::cout << std::endl;
    }
    return 0;
}
