/**
 * @file 587.cpp
 * @brief 安装栅栏
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-23
 */

#include <bits/stdc++.h>
#include "common/utils.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        if (trees.size() <= 3) // 三棵树以下要么是直线，要么是三角形
        {
            return trees;
        }
        remove_reference<decltype(trees)>::type result;
        int x_min, y_min, x_max, y_max;
        x_min = y_min = INT_MAX;
        x_max = y_max = INT_MIN;
        unordered_map<int, vector<int>> x_points; // 以x为键，所有点的纵坐标
        unordered_map<int, vector<int>> y_points; // 以y为键，所有点的横坐标
        for (auto t : trees)
        {
            x_min = min(x_min, t[0]);
            y_min = min(y_min, t[1]);
            x_max = max(x_max, t[0]);
            y_max = max(y_max, t[1]);
            auto x_iter = x_points.find(t[0]);
            auto y_iter = y_points.find(t[1]);
            if (x_iter == x_points.end())
            {
                x_points.insert(make_pair(t[0], vector<int>({t[1]})));
            }
            else
            {
                x_iter->second.push_back(t[1]);
            }
            if (y_iter == y_points.end())
            {
                y_points.insert(make_pair(t[1], vector<int>({t[0]})));
            }
            else
            {
                y_iter->second.push_back(t[0]);
            }
        }
        auto res_x = x_points.find(x_min);
        for (size_t j = 0; j < res_x->second.size(); ++j)
        {
            result.push_back({x_min, res_x->second[j]});
        }
        auto res_y = y_points.find(y_min);
        for (size_t j = 0; j < res_x->second.size(); ++j)
        {
            result.push_back({res_y->second[j], y_min});
        }
        if (x_min == x_max || y_min == y_max)
        {
            return result;
        }
        res_x = x_points.find(x_max);
        for (size_t j = 0; j < res_x->second.size(); ++j)
        {
            result.push_back({x_max, res_x->second[j]});
        }
        res_y = y_points.find(y_max);
        for (size_t j = 0; j < res_y->second.size(); ++j)
        {
            result.push_back({res_y->second[j], y_max});
        }
        for (size_t i = 0; i < result.size(); ++i)
        {
            
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> trees = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
    Solution s;
    auto res = s.outerTrees(trees);
    for (auto var : res)
    {
        print_vector(var);
    }

    return 0;
}
