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
    operator double() const { return value; }
    friend double operator+(ValueDouble &l_v, ValueDouble &r_v);
};

double operator+(ValueDouble &l_v, ValueDouble &r_v)
{
    return l_v.get_value() + r_v.get_value();
}

int main(void)
{
    ValueDouble d1(1.2), d2(5.43);
    ValueDouble res_1 = d1 + d2;  // value = 6.63
    ValueDouble res_2 = d1 + 4.0; // dist = 5.2
    ValueDouble res_3 = 0.3 + d2; // dist = 5.73

    ValueDouble v{8.7};

    ValueDouble &lnk_vd = v;
    ValueDouble &&lnk_r_vd = ValueDouble{8.7};

    return 0;
}