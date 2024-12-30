#include <stdio.h>

enum calc_types
{
    _perimetr = 1,
    _square = 2
};

double calc_rect(double width, double height, enum calc_types type)
{
    if (type == _perimetr)
    {
        return 2 * (width + height);
    }
    else if (type == _square)
    {
        return width * height;
    }
}

int main(void)
{
    int t;
    double w, h;
    scanf("%d %lf %lf", &t, &w, &h);
    printf("%.1f", calc_rect(w, h, t));
    return 0;
}
