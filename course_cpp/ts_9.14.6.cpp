#include <iostream>

using calc_type = enum { calc_perimetr = 0,
                         calc_square = 1 };

int get_rect(int w, int h, calc_type type = calc_perimetr)
{
    return (type) ? (w * h) : (w + h) * 2;
}

double get_rect(double w, double h, calc_type type = calc_perimetr)
{
    return (type) ? (w * h) : (w + h) * 2.0;
}