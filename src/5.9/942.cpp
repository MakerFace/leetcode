/**
 * @file 942.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-09
 */
#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int n = s.size();
        vector<int> result(n + 1);
        int i = 0, j = n;
        int min_value = 0, max_value = n;
        while (i < j)
        {
            if (s[i] == 'D')
            {
                result[i] = max_value--;
            }
            else
            {
                result[i] = min_value++;
            }
            ++i;
        }
        result[i] = min_value;
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    string s;
    while (cin >> s)
        print_vector(ans.diStringMatch(s));
    return 0;
}
