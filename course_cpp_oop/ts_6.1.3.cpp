#include <iostream>
#include <cmath>

template <typename T>
T perimetr(T width, T height)
{
    return 2 * (width + height);
}

template <typename T>
T min_3(T a, T b, T c)
{
    return std::min(a, std::min(b, c));
}

template <typename T>
double hypot(T a, T b)
{
    return sqrt(pow(a, 2) + pow(b, 2));
}

int main(void)
{

    double p2 = perimetr(4, 7);
    short p4 = perimetr<int>(4, 3.2);
    unsigned p6 = perimetr(-1, 8);
    int p1 = perimetr(1, 2);
    long p3 = perimetr(4.5, 3.2);

    int res_1 = min_3(1, -6, 10);
    double res_2 = min_3(0.5, 0.3, 0.1);
    char res_3 = min_3('a', 'b', '0');

    double h1 = hypot(1, 0.5);
    double h2 = hypot(6.3, 0.8);

    return 0;
}