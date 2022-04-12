/**
 * @file 1033.cpp
 * @brief 连续数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-11
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 
 * min={0,1,2}
 * max=a+b+c-2=
 */
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int min_value = min(min(a, b), c);
        int max_value = max(max(a, b), c);
        int mid_value = a + b + c - min_value - max_value;
        int min_move = ((mid_value - 1) > min_value) + ((mid_value + 1) < max_value);
        if ((max_value - mid_value) == 2 || ((mid_value - min_value) == 2))
        {
            min_move = 1;
        }
        int max_move = max_value - min_value - 2;
        return {min_move, max_move};
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.numMovesStones(1,3,5);
    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << std::endl;
    }
    
    return 0;
}
