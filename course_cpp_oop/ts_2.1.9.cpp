#include <iostream>

struct Point
{
    short x, y;
};

class PolyLine
{
    enum
    {
        max_coords = 10
    };
    Point coords[max_coords];
    int total{0};

public:
    PolyLine() : total(0) {}
    PolyLine(const Point *ar, int size_ar)
    {
        set_coords(ar, size_ar);
    }
    void set_coords(const Point *ar, int size)
    {
        for (int i = 0; i < max_coords && i < size; i++)
        {
            coords[i] = ar[i];
            total++;
        }
    }
    void append_coord(Point pt)
    {
        if (total < max_coords)
        {
            coords[total] = pt;
            total++;
        }
    }
    const Point *get_coords()
    {
        return coords;
    }
    int get_total()
    {
        return total;
    }
};

int main(void)
{
    Point coords[20];
    for (int i = 0; i < 20; ++i)
    {
        coords[i].x = i + 1;
        coords[i].y = i + 2;
    }

    PolyLine poly{coords, sizeof(coords) / sizeof(*coords)};
    PolyLine pl;
    pl.append_coord(coords[19]);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}