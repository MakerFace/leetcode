#pragma once
#include <bits/stdc++.h>

template <typename T>
inline void print_vector(std::vector<T> v)
{
    int i = 0;
    std::cout << "[";
    if (!v.empty())
        std::cout << v[i++];
    for (; i < v.size(); ++i)
    {
        std::cout << "," << v[i];
    }
    std::cout << "]";
}
