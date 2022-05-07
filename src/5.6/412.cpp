/**
 * @file 412.cpp
 * @brief Fizz Buzz
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-06
 */
#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result(n);
        for (int i = 1; i <= n; ++i)
        {
            if (not(i % 3) and not(i % 5))
            {
                result[i - 1] = "FizzBuzz";
            }
            else if (not(i % 3))
            {
                result[i - 1] = "Fizz";
            }
            else if (not(i % 5))
            {
                result[i - 1] = "Buzz";
            }
            else
            {
                result[i - 1] = to_string(i);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int n;
    while (cin >> n)
    {
        print_vector(ans.fizzBuzz(n));
        std::cout << std::endl;
    }
    return 0;
}
