#include <iostream>

class Clock
{
    unsigned tm{0};

public:
    unsigned get_time() const
    {
        return tm;
    }
    Clock() {}
    Clock(unsigned t) : tm(t) {}
    operator unsigned() const { return tm; }
    unsigned operator+(const Clock &other)
    {
        return tm + other.tm;
    }
    unsigned operator+=(const Clock &other)
    {
        tm += other.tm;
        return tm;
    }
    unsigned operator-=(const Clock &other)
    {
        if (tm - other.tm < 0)
        {
            tm = 0;
            return tm;
        }
        tm -= other.tm;
        return tm;
    }
    unsigned operator++() { return ++tm; }
    unsigned operator++(int) { return tm++; }
    unsigned operator--()
    {
        return --tm < 0 ? 0 : tm;
    }
    unsigned operator--(int)
    {
        return tm - 1 < 0 ? 0 : tm--;
    }
};

int main(void)
{
    Clock clock_1(100), clock_2(430);
    Clock cl1(40), cl2(1000);
    Clock res = cl1 + cl2;  // cl1.tm + cl2.tm (объекты cl1, cl2 не меняются)
    Clock r_1 = cl1 += 10;  // tm += 10
    Clock r_2 = cl2 -= 10;  // tm -= 10
    Clock r_3 = cl2 += cl1; // cl2.tm += cl1.tm
    Clock r_4 = cl1 -= cl2; // cl1.tm -= cl2.tm
    unsigned tm_1 = cl1++;  // tm++
    unsigned tm_2 = ++cl1;  // ++tm
    unsigned tm_3 = cl1--;  // tm--
    unsigned tm_4 = --cl1;  // --tm

    return 0;
}