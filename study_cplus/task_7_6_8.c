#include <stdio.h>

enum
{
    total_points = 100
};

struct tag_point_3d
{
    int x, y, z;
};

int main(void)
{
    struct tag_point_3d points[total_points];
    int x, y, z, indx = 0, total = 0;
    while ((scanf("%d %d %d", &x, &y, &z) == 3) && indx < total_points)
    {
        points[indx].x = x;
        points[indx].y = y;
        points[indx].z = z;
        ++indx;
        total += 3;
    }
    printf("%d %d %d", points[indx - 1].x, points[indx - 1].y, points[indx - 1].z);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}