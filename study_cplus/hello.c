#include <stdio.h>

int main(void)
{
    int a = 6, b = 15;
    double c = 0.3;
    double res = a * (c * c) - b * c;
    printf("%.2lf", res);

    return 0;
}