#include <iostream>
#include <math.h>

using std::max;
using std::min;

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

bool is_point_in_polygon(int x, int y, point figure[], const double total_area)
{
    double current_area = 0;

    for (int i = 0; i < corners; i++)
    {
        int next = (i + 1) % corners;
        double a = get_len_segment(figure[i].x, figure[i].y, figure[next].x, figure[next].y);
        double b = get_len_segment(figure[i].x, figure[i].y, x, y);
        double c = get_len_segment(figure[next].x, figure[next].y, x, y);
        current_area += get_area_triangle(a, b, c);
    }

    return fabs(total_area - current_area) < 1e-10;
}

int main()
{
    point figure[corners];
    int x_min, x_max, y_min, y_max, result = 0, count = 0;
    const double eps = 1e-10;
    double s1, s2, s3, s4, s5, total_area;

    while (count < corners && scanf("%d; %d", &figure[count].x, &figure[count].y) == 2)
        count++;

    if (count != corners)
    {
        puts("Неверное количество или формат входных данных.");
        return 1;
    }

    x_min = min(min(min(figure[0].x, figure[1].x), figure[2].x), figure[3].x);
    x_max = max(max(max(figure[0].x, figure[1].x), figure[2].x), figure[3].x);
    y_min = min(min(min(figure[0].y, figure[1].y), figure[2].y), figure[3].y);
    y_max = max(max(max(figure[0].y, figure[1].y), figure[2].y), figure[3].y);

    s1 = get_len_segment(figure[0].x, figure[0].y, figure[1].x, figure[1].y);
    s2 = get_len_segment(figure[1].x, figure[1].y, figure[2].x, figure[2].y);
    s3 = get_len_segment(figure[2].x, figure[2].y, figure[3].x, figure[3].y);
    s4 = get_len_segment(figure[3].x, figure[3].y, figure[0].x, figure[0].y);

    s5 = get_len_segment(figure[0].x, figure[0].y, figure[2].x, figure[2].y);

    total_area = get_area_triangle(s1, s2, s5) + get_area_triangle(s3, s4, s5);

    for (int i = x_min; i <= x_max; ++i)
    {
        for (int j = y_min; j <= y_max; ++j)
        {
            if (is_point_in_polygon(i, j, figure, total_area))
            {
                ++result;
            }
        }
    }

    std::cout << result << std::endl;
    return 0;
}