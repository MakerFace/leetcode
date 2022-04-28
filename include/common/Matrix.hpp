#pragma once
#include "common/utils.hpp"
#include <bits/stdc++.h>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

template <typename T>
void print_matrix(const Matrix<T> &matrix)
{
    std::cout << "[";
    for (auto var : matrix)
    {
        print_vector(var);
        std::cout << ",";
    }
    std::cout << "\b]";
}