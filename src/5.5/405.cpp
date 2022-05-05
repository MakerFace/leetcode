/**
 * @file 405.cpp
 * @brief 数字转换为十六进制数
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-05
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<char> table = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

public:
    string toHex(int num)
    {
        string result;
        if (num > 0)
        {
            while (num)
            {
                result.insert(0, 1, table[num % 16]);
                num /= 16;
            }
        }
        else if (num == 0)
        {
            result += '0';
        }
        else
        {
            num += INT_MAX;
            num += 1;

            for (int i = 0; i < 7; ++i)
            {
                result.insert(0, 1, table[num % 16]);
                num /= 16;
            }
            result.insert(0, 1, table[num % 16 + 8]);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int n;
    while (cin >> n)
        std::cout << ans.toHex(n) << std::endl;
    return 0;
}
