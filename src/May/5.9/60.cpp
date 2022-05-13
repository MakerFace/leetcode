/**
 * @file 60.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-09
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string result;
        for (int i = 0; i < n; ++i)
        {
            result += i + '1';
        }
        for (int i = 1; i < k; ++i)
        {
            next_permutation(result.begin(), result.end());
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int n, k;
    while (cin >> n >> k)
        cout << ans.getPermutation(n, k) << endl;
    return 0;
}
