#include <iostream>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()

enum
{
    total_points = 128
};

struct tag_point
{
    float x;
    float y;
};

int main()
{
    tag_point ps[total_points];

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < total_points; ++i)
    {
        ps[i].x = static_cast<float>(std::rand()) / RAND_MAX * 200.0f - 100.0f;
        ps[i].y = static_cast<float>(std::rand()) / RAND_MAX * 200.0f - 100.0f;
    }

    double sum_x = 0.0, sum_y = 0.0;

    for (int i = 0; i < total_points; ++i)
    {
        sum_x += ps[i].x;
        sum_y += ps[i].y;
    }

    double mean_x = sum_x / total_points;
    double mean_y = sum_y / total_points;

    return 0;
}