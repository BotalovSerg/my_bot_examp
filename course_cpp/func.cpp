#include <iostream>
#include <cmath>
#include <stdio.h>

double triangle_sq(int a, int b, int c)
{
    double p = (a + b + c) / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    printf("%.2f", triangle_sq(a, b, c));
    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}