/**
 * @file 868.cpp
 * @brief 二进制间距
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-24
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binaryGap(int n)
    {
        int len = INT_MIN;
        int count = 0;
        bool found = false;
        while (n)
        {
            if (n % 2)
                break;
            n /= 2;
        }
        if (n)
        {
            found = true;
            count = 0;
            n /= 2;
        }
        while (n)
        {
            found = n % 2;
            n /= 2;
            if (!found)
            {
                ++count;
            }
            else
            {
                len = max(count + 1, len);
                count = 0;
            }
        }
        len = max(count, len);
        return len;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    cin >> n;
    std::cout << s.binaryGap(n) << std::endl;
    return 0;
}
