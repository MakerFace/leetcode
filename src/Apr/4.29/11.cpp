/**
 * @file 11.cpp
 * @brief 盛最多水的容器
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-29
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int area = 0;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            int temp = (j - i) * min(height[i], height[j]);
            if (temp > area)
            {
                area = temp;
            }
            if (i < j)
            {
                if (height[i] < height[j])
                    ++i;
                else
                    --j;
            }
        }
        return area;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int n;
    while (cin >> n)
    {
        vector<int> height(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> height[i];
        }
        std::cout << ans.maxArea(height) << std::endl;
    }
    return 0;
}
