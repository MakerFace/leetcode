/**
 * @file 1496.cpp
 * @brief 判断路径是否相交
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-15
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        unordered_set<string> uset;
        uset.reserve(path.size());
        int x = 0, y = 0;
        uset.insert(int2string(x, y));
        for (auto p = path.begin(); p != path.end(); p++)
        {
            switch (*p)
            {
            case 'N':
                ++y;
                break;
            case 'S':
                --y;
                break;
            case 'E':
                ++x;
                break;
            case 'W':
                --x;
                break;
            default:
                break;
            }
            string temp = int2string(x, y);
            auto res = uset.insert(temp);
            if (!res.second)
                return true;
        }
        return false;
    }

private:
    string int2string(int x, int y)
    {
        string res;
        res.append(to_string(x));
        res.append(to_string(y));
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << boolalpha << s.isPathCrossing("NESW") << std::endl;
    return 0;
}