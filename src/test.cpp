#include <iostream>

using namespace std;

class test
{
private:
    int *value;

public:
    test(int i)
    {
        value = new int(i);
        std::cout << "Constructor" << *value << std::endl;
        ++*value;
    }
    test(const test &t)
    {
        value = new int(*t.value);
        std::cout << "copy constructor" << *value << std::endl;
        ++*value;
    }
    test(test &&t)
    {
        value = t.value;
        t.value = nullptr;
        std::cout << "move constructor" << *value << std::endl;
        ++*value;
    }
    ~test()
    {
        if (value != nullptr)
            delete value;
    }
};

static test getTest()
{
    static int i = 1;
    test t(i);
    return t;
}

int main(int argc, char const *argv[])
{
    test trf = getTest();
    test trf1(getTest());
    return 0;
}
