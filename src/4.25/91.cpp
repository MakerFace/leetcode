/**
 * @file 91.cpp
 * @brief 解码方法
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-25
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 爬楼梯
 *
            if ((i > 1 && s[i - 1] == '3') ||                // 碰到前一位是3只能走一步
                (i > 1 && s[i - 1] == '0') ||                //前一位是0只能走一步
                (i > 1 && s[i - 1] == '2' && s[i] >= '7') || // 当前是7，8，9而前一位是2只能走一步
                (i + 1 < s.size() && s[i + 1] == '0'))       //后一位是0，只能走一步
            {
                dp[i + 1] = dp[i];
            }
            else // 既可以走两步，也可以走一步
            {
                if (i < 1)
                    dp[i + 1] = 1;
                else
                    dp[i + 1] = dp[i] + dp[i - 1];
            }
 */
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        vector<int> dp(s.size() + 1);
        dp[0] = dp[1] = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            if ((i + 1 < s.size() && s[i + 1] == '0')) // 后一位为0，只能走两步，一种状态
            {
                if (s[i] == '1' || s[i] == '2')
                    dp[i + 1] = dp[i + 2] = dp[i];
                else
                    return 0;
                ++i;
            }
            else if (s[i] == '0')
                return 0;
            else if ((s[i] >= '7' && i > 0 && s[i - 1] >= '2' && s[i] != '0') || // 当前7,8,9前面是不是1，只能走一步
                     (i > 0 && ((s[i - 1] >= '3') || (s[i - 1] == '0'))))        // 前一位是0,3~9，只能走一步

            {
                dp[i + 1] = dp[i];
            }
            else if (i > 0 && ((s[i - 1] == '1') ||               // 前一位是1，当前任意
                               (s[i - 1] == '2' && s[i] <= '6'))) // 前一位是2，当前是1~6
            {
                dp[i + 1] = dp[i] + dp[i - 1];
            }
        }
        return dp[s.size()];
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    string s;
    while (true)
    {
        cin >> s;
        std::cout << ans.numDecodings(s) << std::endl;
    }
    return 0;
}
