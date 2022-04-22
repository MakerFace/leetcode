/**
 * @file 67.cpp
 * @brief 二进制求和
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-21
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string res(max(i, j) + 1, 0);
        int cur = res.size() - 1;
        int8_t t = 0;
        while (i >= 0 && j >= 0)
        {
            t += a[i] + b[j] - 96;
            add(res, cur, t);
            --i;
            --j;
        }
        while (i >= 0)
        {
            t += a[i] - '0';
            add(res, cur, t);
            --i;
        }
        while (j >= 0)
        {
            t += b[j] - '0';
            add(res, cur, t);
            --j;
        }
        while (t != 0)
        {
            if (t == 98)
            {
                res.insert(res.begin(), 1, t % 2 + '0');
                t /= 2;
            }
            else
            {
                res.insert(res.begin(), 1, t + '0');
                t = 0;
            }
        }
        return res;
    }

private:
    void add(string &res, int &cur, int8_t &t)
    {
        if (t >= 2)
        {
            res[cur--] = t % 2 + '0';
            t /= 2;
        }
        else
        {
            res[cur--] = t + '0';
            t = 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string a, b;
    cin >> a;
    cin >> b;
    std::cout << s.addBinary(a, b) << std::endl;
    return 0;
}
