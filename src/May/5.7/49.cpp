/**
 * @file 49.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-07
 */
#include <bits/stdc++.h>
#include "common/Matrix.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        string tmp;
        for (auto s : strs)
        {
            tmp = s;
            sort(tmp.begin(), tmp.end());
            auto iter = map.find(tmp);
            if (iter == map.end())
            {
                map.insert(make_pair(tmp, vector<string>({s})));
            }
            else
            {
                iter->second.push_back(s);
            }
        }
        vector<vector<string>> result;
        for (auto m : map)
        {
            result.push_back(m.second);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> strs = {"", ""};
    Solution ans;
    auto res = ans.groupAnagrams(strs);
    print_matrix(res);
    return 0;
}