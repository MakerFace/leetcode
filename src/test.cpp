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

struct alignas(4) s
// #pragma pack(4)
// struct s
{
    uint8_t a;
    uint16_t b;
    uint8_t c;
};
struct foo
{
    int i;
    double d;
    char c;
};

struct alignas(16) foo_n
{
    int i;
    float d;
    char c;
};

int main(int argc, char const *argv[])
{
    std::cout << sizeof(s) << std::endl;
    s t;
    t.a = 1;
    t.b = 2;
    t.c = 3;
    std::cout << hex << (void *)(&t.a) << std::endl;
    std::cout << hex << (void *)(&t.b) << std::endl;
    std::cout << hex << (void *)(&t.c) << std::endl;
    return 0;
}
