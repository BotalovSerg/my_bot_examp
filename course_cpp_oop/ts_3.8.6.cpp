#include <iostream>

class ValueDouble
{
    double value{0.0};

public:
    double get_value() const
    {
        return value;
    }
    ValueDouble(double v = 0) : value(v) {}
    friend double operator+(ValueDouble &l_v, ValueDouble &r_v);
};

double operator+(ValueDouble &l_v, ValueDouble &r_v)
{
    return 0.0;
}
