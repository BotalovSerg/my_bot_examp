#include <iostream>
#include <cstdio>

struct tag_point_3d
{
    int x, y, z;
};

enum
{
    total_points = 100
};


struct tag_thing {
    unsigned int id;
    char name[50];
    double weight;
    double price;
};

int main(void)
{
    struct tag_thing thing_1 = {1, "book", 0.5, 3500.0};

    struct tag_thing thing_3 = {.id=1};

    struct tag_thing thing_2 = {1, "book"};

    struct tag_thing thing_4 = {.id = 5, .name="toy"};

    tag_point_3d points[total_points];
    int x, y, z, total = 0;
    while (scanf("%d %d %d", &x, &y, &z) == 3)
    {
        points[total].x = x;
        points[total].y = y;
        points[total].z = z;
        total++;
    }
    std::cout << points[0].x << ' ' << points[0].y << ' ' << points[0].z << std::endl;

    return 0;
}
