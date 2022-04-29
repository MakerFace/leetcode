/**
 * @file 1122.cpp
 * @brief 数组的相对排序
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-29
 */
#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int k = 0;
        for (int i = 0; i < arr2.size(); ++i)
        {
            for (int j = k; j < arr1.size(); ++j)
            {
                if (arr2[i] == arr1[j])
                {
                    swap(arr1[j], arr1[k++]);
                }
            }
        }
        if (k < arr1.size())
        {
            sort(arr1.begin() + k, arr1.end());
        }
        return arr1;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    vector<int> arr1 = {28, 6, 22, 8, 44, 17};
    vector<int> arr2 = {22, 28, 8, 6};
    auto res = ans.relativeSortArray(arr1, arr2);
    print_vector(res);
    std::cout << std::endl;
    return 0;
}
