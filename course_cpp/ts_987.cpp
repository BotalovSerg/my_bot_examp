#include <iostream>
#include <math.h>

enum
{
    corners = 4
};

struct point
{
    int x, y;
};

double get_len_segment(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double get_area_triangle(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
    point figure[corners];
    point pt;
    const double eps = 1e-10;
    double s1, s2, s3, s4, s5, area1, area2, s_x1, s_x2, s_x3, s_x4, area3, area4, area5, area6;

    int count = 0;
    while (count < corners && scanf("%d; %d", &figure[count].x, &figure[count].y) == 2)
        count++;

    if (count != corners)
    {
        puts("Неверное количество или формат входных данных.");
        return 1;
    }

    s1 = get_len_segment(figure[0].x, figure[0].y, figure[1].x, figure[1].y);
    s2 = get_len_segment(figure[1].x, figure[1].y, figure[2].x, figure[2].y);
    s3 = get_len_segment(figure[2].x, figure[2].y, figure[3].x, figure[3].y);
    s4 = get_len_segment(figure[3].x, figure[3].y, figure[0].x, figure[0].y);

    s5 = get_len_segment(figure[0].x, figure[0].y, figure[2].x, figure[2].y);

    area1 = get_area_triangle(s1, s2, s5);
    area2 = get_area_triangle(s3, s4, s5);

    if (fabs((area1 + area2) - (area3 + area4 + area5 + area6)) < eps)
    {
        std::cout << "yes" << '\n';
    }
    else
    {
        std::cout << "no" << '\n';
    }

    return 0;
}