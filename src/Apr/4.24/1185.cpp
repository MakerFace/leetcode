/**
 * @file 1185.cpp
 * @brief 一周的第几天
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-24
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 1971.1.1 是周五
 */
class Solution
{
public:
    string dayOfTheWeek(int day, int month, int year)
    {
        int days = 0;
        if (year > 1971)
        {
            // years
            for (int y = 1971; y < year; ++y)
            {
                days += 365;
                if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                {
                    ++days;
                }
            }
        }
        // current year
        if (month > 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                days += 1;
            }
        }
        for (int m = 1; m < month; ++m)
        {
            days += day_month[m - 1];
        }
        days += day;
        return month_map[((days) % 7 + 4) % 7];
    }

private:
    vector<int> day_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> month_map = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
};

int main(int argc, char const *argv[])
{
    Solution ans;
    int day, month, year;
    cin >> day >> month >> year;
    std::cout << ans.dayOfTheWeek(day, month, year) << std::endl;
    return 0;
}
