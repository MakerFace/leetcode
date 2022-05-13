/**
 * @file 1108.cpp
 * @brief IP地址无效化
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-29
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string defangIPaddr(string address)
    {
        int pos = address.find(".");
        while (pos > 0)
        {
            address.insert(pos + 1, "]");
            address.insert(pos, "[");
            pos = address.find(".", pos + 2);
        }

        return address;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    std::cout << ans.defangIPaddr("255.100.50.0") << std::endl;
    return 0;
}
