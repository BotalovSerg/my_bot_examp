#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

struct vector4D
{
    double x, y, z, t;

    void read_data(FILE *stream, char sep = ' ')
    {
        fscanf(stream, "%lf%c%lf%c%lf%c%lf", &x, &sep, &y, &sep, &x, &sep, &t);
    }

    double length()
    {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(t, 2));
    }
};

int main(void)
{
    vector4D v1, v2;
    v1.read_data(stdin, ';');
    v2.read_data(stdin, ';');

    std::cout << std::fixed << std::setprecision(3) << v1.length() << ' ' << v2.length() << std::endl;

    return 0;
}