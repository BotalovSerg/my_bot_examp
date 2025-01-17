#include <iostream>
#include <math.h>

using POINT = struct
{
    double x, y;
};

double get_length(const POINT &point_1, const POINT &point_2)
{
    double result = sqrt(pow(point_1.x - point_2.x, 2) + pow(point_1.y - point_2.y, 2));
    return result;
}

int main(void)
{
    POINT p1 = {-2.5, 7.8}, p2 = {11.4, 43.2};
    printf("%.2f", get_length(p1, p2));
    return 0;
}