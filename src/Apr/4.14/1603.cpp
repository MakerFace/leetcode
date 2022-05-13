/**
 * @file 1603.cpp
 * @brief 设计停车系统
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-14
 */

#include <bits/stdc++.h>

using namespace std;

class ParkingSystem
{
private:
    int big, medium, small;

public:
    ParkingSystem(int big, int medium, int small)
        : big(big), medium(medium), small(small)
    {
    }

    bool addCar(int carType)
    {
        switch (carType)
        {
        case 1:
            if (big <= 0)
                return false;
            --big;
            break;
        case 2:
            if (medium <= 0)
                return false;
            --medium;
            break;
        case 3:
            if (small <= 0)
                return false;
            --small;
            break;
        default:
            return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    ParkingSystem parkingSystem(1, 1, 0);
    cout << boolalpha << parkingSystem.addCar(1) << endl;
    cout << boolalpha << parkingSystem.addCar(2) << endl;
    cout << boolalpha << parkingSystem.addCar(3) << endl;
    cout << boolalpha << parkingSystem.addCar(1) << endl;
    return 0;
}
