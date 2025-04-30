#include <iostream>

class AbsoluteValue
{

public:
    unsigned long value{0};
    AbsoluteValue() {}
    AbsoluteValue(int v)
    {
        if (v < 0)
        {
            value = -v;
        }
        else
        {
            value = v;
        }
    }
    AbsoluteValue &operator=(const AbsoluteValue &other)
    {
        if (this == &other)
        {
            return *this;
        }
        this->value = other.value;
        return *this;
    }
};

int main(void)
{

    AbsoluteValue *ptr_abv = new AbsoluteValue;
    *ptr_abv = -512;

    AbsoluteValue v1; // value = 0
    AbsoluteValue v2 = 100;
    delete ptr_abv;
    return 0;
}