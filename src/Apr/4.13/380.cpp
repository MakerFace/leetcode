/**
 * @file 380.cpp
 * @brief 时间插入、删除、获取随机元素
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-13
 */

#include <bits/stdc++.h>

using namespace std;

class RandomizedSet
{
private:
    unordered_map<int, int> map;
    vector<int> vec;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        auto iter = map.find(val);
        if (iter == map.end())
        {
            map.insert(pair<int, int>(val, vec.size()));
            vec.push_back(val);
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        auto iter = map.find(val);
        if (iter != map.end())
        {
            int end_vec = *(vec.cend() - 1);
            if (val != end_vec)
            {
                auto end_iter = map.find(end_vec);
                // 交换被删除元素和尾元素
                swap(vec[iter->second], *(vec.end() - 1));
                // 交换被删除元素和尾元素索引
                swap(iter->second, end_iter->second);
            }

            vec.erase(vec.end() - 1);
            map.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        return vec[random() % vec.size()];
    }
};

int main(int argc, char const *argv[])
{
    RandomizedSet radomizedSet;
    cout << boolalpha << radomizedSet.insert(1) << endl;
    cout << boolalpha << radomizedSet.remove(2) << endl;
    cout << boolalpha << radomizedSet.insert(2) << endl;
    cout << radomizedSet.getRandom() << endl;
    cout << boolalpha << radomizedSet.remove(1) << endl;
    cout << boolalpha << radomizedSet.insert(2) << endl;
    cout << radomizedSet.getRandom() << endl;
    return 0;
}
