/**
 * @file 6.cpp
 * @brief Z字形变换
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-03-01
 */

#include <string>
#include <iostream>

using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        string res;
        int start[numRows];
        for (size_t i = 0; i < numRows; i++)
        {
            start[i] = 0;
        }
        
        int index = 0;
        bool add = true;
        for (size_t i = 0; i < s.size(); i++)
        {
            res.insert(start[index], 1, s[i]);
            for (size_t j = index; j < numRows; j++)
            {
                start[j]++;
            }

            if (add)
            {
                index++;
            }
            else
            {
                index--;
            }
            if (index < 0)
            {
                index = 1;
                add = true;
            }
            else if (index >= numRows)
            {
                index = numRows - 2;
                add = false;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string str = "PAYPALISHIRING";
    Solution s;
    auto res = s.convert(str, 2);
    std::cout << res << std::endl;
    return 0;
}
