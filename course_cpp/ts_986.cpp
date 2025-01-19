#include <iostream>
#include <math.h>

struct point
{
    int x, y;
};

double sq_tr(point &a, point &b, point &c)
{
    double l1, l2, l3, p;
    l1 = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    l2 = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
    l3 = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
    p = (l1 + l2 + l3) / 2;
    return sqrt(p * (p - l1) * (p - l2) * (p - l3));
}

int main()
{
    point a, b, c;
    std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    printf("%.2f", sq_tr(a, b, c));

    return 0;
}