#include <iostream>

class Distance
{
    long dist{0};

public:
    Distance() {}
    Distance(long d) : dist(d) {}
    friend void set_distance(Distance &dst, long value);
    friend long get_distance(const Distance &dst);
    friend double distance_to_meters(const Distance &dst);
    friend Distance operator+(const Distance &r, const Distance &l);
    friend Distance operator+(long r, Distance &l);
    friend Distance operator+(Distance &r, long l);
};

void set_distance(Distance &dst, long value)
{
    dst.dist = value;
}

long get_distance(const Distance &dst)
{
    return dst.dist;
}

double distance_to_meters(const Distance &dst)
{
    return static_cast<double>(dst.dist) / 1000;
}

Distance operator+(const Distance &r, const Distance &l)
{
    return Distance(r.dist + l.dist);
}

Distance operator+(long r, Distance &l)
{
    return Distance(r + l.dist);
}

Distance operator+(Distance &r, long l)
{
    return Distance(r.dist + l);
}

int main(void)
{
    Distance d{783};
    printf("%ld %.2f", get_distance(d), distance_to_meters(d));

    Distance d1(100), d2(543);
    Distance res_1 = d1 + d2;  // dist = 643
    Distance res_2 = d1 + 500; // dist = 600
    Distance res_3 = 10 + d2;
    return 0;
}